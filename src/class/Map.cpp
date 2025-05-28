#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Map.hpp"

Map::Map() {}

bool pointInConvex(const sf::ConvexShape& shape, sf::Vector2f point) {
  size_t count = shape.getPointCount();
  if (count < 3) return false;

  const float epsilon = 1e-6f;
  for (size_t i = 0; i < count; ++i) {
      sf::Vector2f a = shape.getTransform().transformPoint(shape.getPoint(i));
      sf::Vector2f b = shape.getTransform().transformPoint(shape.getPoint((i + 1) % count));
      sf::Vector2f edge = b - a;
      sf::Vector2f toPoint = point - a;

      float crossProduct = edge.x * toPoint.y - edge.y * toPoint.x;
      if (crossProduct < -epsilon)
          return false;
  }

  return true;
}

void Map::draw(sf::RenderWindow& window, int mapX, int mapY, double zoom) {
  for (Chunk chunk : chunks) {
    chunk.convex.setPosition({mapX, mapY});
    chunk.convex.setScale({zoom*1.f, zoom*1.f});
    window.draw(chunk.convex);
  }
}

Biome Map::getCordsChunk(sf::RenderWindow& window, int x, int y, int mapX, int mapY, double zoom) {
  sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
  sf::Vector2f position({static_cast<float>((mousePosition.x-mapX)/zoom), static_cast<float>((mousePosition.y-mapY)/zoom)});

  Biome biome = Grass;
  for (Chunk chunk : chunks) {
    if (pointInConvex(chunk.convex, position)) {
      biome = chunk.biome;
    }
  }
  return biome;
}