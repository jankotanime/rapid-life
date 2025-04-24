#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bear.hpp"
#include <cstdlib>
#include <math.h>

Bear::Bear(int x, int y, int s, int v) : Animal(x, y, s, v) {
  speed = 0.1;
  shape.setFillColor(sf::Color(100, 80, 30));
}

void Bear::chooseDetractor() {
  attractors = std::forward_list<std::shared_ptr<Object>>();
      repulsers = std::forward_list<std::shared_ptr<Object>>();
  findDirection();
}
