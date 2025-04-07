#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>
#include <iostream>
#include "Object.hpp"
#include "Fruit.hpp"
#include "Animal.hpp"
#include "Map.hpp"

class App {
public:
  int WIDTH = 800;
  int HEIGHT = 600;
  int mapWIDTH = 1600;
  int mapHEIGHT = 1200;
  int menu = true;
  int start = false;
  int initial = false;
  int x, y;
  double zoom;
  std::forward_list<Animal> animals;
  std::forward_list<Object> fruits;
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
