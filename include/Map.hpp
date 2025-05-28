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
  Biome getCordsChunk(sf::RenderWindow&, int, int, int, int, double);
  private:
  std::forward_list<Chunk> chunks;
  int borderX;
  int borderY;
};

#endif