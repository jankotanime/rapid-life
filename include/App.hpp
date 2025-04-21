#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>
#include <iostream>
#include "Object.hpp"
#include "Fruit.hpp"
#include "Animal.hpp"
#include "Pig.hpp"
#include "Bear.hpp"
#include "Map.hpp"
#include "Carrot.hpp"
#include "Rabbit.hpp"
#include "Corpse.hpp"

class App {
public:
  int WIDTH = 800;
  int HEIGHT = 600;
  int mapWIDTH = 2000; // best 2000 - 4000
  int mapHEIGHT = 2000; // best 2000 - 4000
  bool menu = true;
  bool start = false;
  bool initial = false;
  bool debug = false;
  int updateTick = 1;
  int x, y;
  double zoom;
  std::forward_list<Animal> animals;
  std::forward_list<Fruit> fruits;
  std::forward_list<Corpse> corpses;
  App(sf::ContextSettings, std::string);
  void run();
  
  private:
  void processEvents();
  void update(sf::Time);
  void render();
  void init();
  void close();
  sf::RenderWindow window;
  Map map;
};

#endif
