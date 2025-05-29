#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Map.hpp"

Map::Map() {}

int Map::getBorderX() {
  return borderX;
}

int Map::getBorderY() {
  return borderY;
}

bool pointInConvex(const sf::ConvexShape& shape, sf::Vector2f point) {
  size_t count = shape.getPointCount();
  if (count < 3) return false;

  bool inside = false;
  for (size_t i = 0; i < count; ++i) {
    sf::Vector2f a = shape.getTransform().transformPoint(shape.getPoint(i));
    sf::Vector2f b = shape.getTransform().transformPoint(shape.getPoint((i + 1) % count));

    if ((a.y > point.y) != (b.y > point.y) && 
    (point.x < (b.x - a.x) *  (point.y - a.y) / (b.y - a.y) + a.x)) {
      inside = !inside;
    }
  }
  return inside;
}

void Map::draw(sf::RenderWindow& window, int mapX, int mapY, double zoom) {
  for (Chunk chunk : chunks) {
    chunk.convex.setPosition({mapX, mapY});
    chunk.convex.setScale({zoom*1.f, zoom*1.f});
    window.draw(chunk.convex);
  }
}

Biome Map::getCordsChunk(sf::Vector2f position) {
  Biome biome = Grass;
  for (Chunk chunk : chunks) {
    if (pointInConvex(chunk.convex, position)) {
      biome = chunk.biome;
    }
  }
  return biome;
}

bool Map::isPointInBiomes(std::forward_list<Biome> biomes, sf::Vector2f position) {
  for (Chunk chunk : chunks) {
    if (pointInConvex(chunk.convex, position)) {
      for (Biome biome : biomes) {
        if (biome == chunk.biome) {
          return true;
        }
      }
    }
  }
  return false;
}