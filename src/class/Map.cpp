#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Map.hpp"

Map::Map() {}

void Map::draw(sf::RenderWindow& window, int mapX, int mapY, double zoom) {
  for (Chunk chunk : chunks) {
    chunk.convex.setPosition({mapX, mapY});
    chunk.convex.setScale({zoom*1.f, zoom*1.f});
    window.draw(chunk.convex);
  }
}