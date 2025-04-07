#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Map.hpp"

Biome getRandomBiome() {
    int r = rand() % 100;
    if (r < 70) return Grass;
    else if (r < 90) return Forest;
    else return Water;
}

Map::Map() {}

Map::Map(int x, int y) : borderX(x), borderY(y) {
  for (int actY = 0; actY < borderY;) {
    int actEndY = actY + (rand() % 21)+100;
    if (actEndY >= borderY) {
      actEndY = borderY;
    }
    int actX = 0;
    int actEndX = 0;
    while (actX < borderX) {
      sf::ConvexShape convex;
      std::vector<sf::Vector2f> points;
      points.push_back({static_cast<float>(actX), static_cast<float>(actY)});
      points.push_back({static_cast<float>(actEndX), static_cast<float>(actEndY)});
      actX += (rand() % 21)+100;
      actEndX += (rand() % 21)+100;
      if (actEndX >= borderX || actX >= borderX) {
        actX = borderX;
        actEndX = borderX;
      }
      points.push_back({static_cast<float>(actEndX), static_cast<float>(actEndY)});
      points.push_back({static_cast<float>(actX), static_cast<float>(actY)});
      convex.setPointCount(points.size());
      for (int i = 0; i < 4; i++) {
        convex.setPoint(i, points[i]);
      }
      Biome biome = getRandomBiome();
      switch (biome)
      {
      case Grass:
        convex.setFillColor(sf::Color(80, 200, 100));
        break;
      case Water:
        convex.setFillColor(sf::Color(20, 20, 140));
        break;
      case Forest:
        convex.setFillColor(sf::Color(40, 140, 40));
        break;
      default:
        break;
      }
      chunks.push_front({convex, biome});
    }
    actY = actEndY;
  }
}

void Map::draw(sf::RenderWindow& window, int mapX, int mapY, double zoom) {
  for (Chunk chunk : chunks) {
    chunk.convex.setPosition({mapX, mapY});
    chunk.convex.setScale({zoom*1.f, zoom*1.f});
    window.draw(chunk.convex);
  }
}