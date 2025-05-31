#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "./enum/Biome.hpp"
#include <SFML/Graphics.hpp>
#include "Map.hpp"

class Debug {
  public:
  Debug(int, int, int, int);
  void paintMouseCords(sf::RenderWindow&, Map, int, int, double, float);
  void show();
  bool getShown();
  private:
  int WIDTH; 
  int HEIGHT; 
  int mapWIDTH;
  int mapHEIGHT;
  bool shown = false;
};

#endif