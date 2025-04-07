#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>
#include <iostream>

enum Biome { Grass, Water, Forest };

struct Chunk {
  sf::ConvexShape convex;
  Biome biome;
};

class Map {
  public:
  Map(int, int);
  Map();
  void draw(sf::RenderWindow&, int, int);
  private:
  std::forward_list<Chunk> chunks;
  int borderX;
  int borderY;
};

#endif