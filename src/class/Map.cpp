#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Map.hpp"

Biome getRandomBiome() {
    int r = rand() % 100;
    if (r < 60) return Grass;
    else if (r < 90) return Forest;
    else return Water;
}


Map::Map() {}

Map::Map(int x, int y) : borderX(x), borderY(y) {
  for (int actY = 0; actY < borderY;) {
    int actEndY = actY + (rand() % 21)+40;
    if (actEndY >= 500) {
      actEndY = 500;
    }
    int actX = 0;
    int actEndX = 0;
    while (actX < borderX) {
      sf::ConvexShape convex;
      std::vector<sf::Vector2f> points;
      points.push_back({static_cast<float>(actX), static_cast<float>(actY)});
      points.push_back({static_cast<float>(actEndX), static_cast<float>(actEndY)});
      actX += (rand() % 21)+40;
      actEndX += (rand() % 21)+40;
      if (actEndX >= borderX || actX >= borderX) {
        actX = borderX;
        actEndX = borderX;
      }
      points.push_back({static_cast<float>(actX), static_cast<float>(actY)});
      points.push_back({static_cast<float>(actEndX), static_cast<float>(actEndY)});
      convex.setPointCount(points.size());
      convex.setPoint(0, points[0]);
      convex.setPoint(1, points[1]);
      convex.setPoint(3, points[2]);
      convex.setPoint(2, points[3]);
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

void Map::draw(sf::RenderWindow& window) {
  for (Chunk chunk : chunks) {
    window.draw(chunk.convex);
  }
}