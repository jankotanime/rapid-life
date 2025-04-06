#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>
#include <iostream>
#include "Object.hpp"

class App {
public:
  int WIDTH = 800;
  int HEIGHT = 600;
  int menu = true;
  int start = false;
  int initial = false;
  std::forward_list<Object> objects;
  App();
  void run();

private:
  void processEvents();
  void update(sf::Time);
  void render();
  void init();
  void close();
  sf::RenderWindow window;
};

#endif
