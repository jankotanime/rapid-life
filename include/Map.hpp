#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>
#include <iostream>
#include "./enum/Biome.hpp"

struct Chunk {
  sf::ConvexShape convex;
  Biome biome;
};

class Map {
  public:
  Map(int, int);
  Map();
  void draw(sf::RenderWindow&, int, int, double);
  Biome getCordsChunk(sf::Vector2f);
  int getBorderX();
  int getBorderY();
  bool isPointInBiomes(std::forward_list<Biome>, sf::Vector2f);
  private:
  std::forward_list<Chunk> chunks;
  int borderX;
  int borderY;
};

#endif