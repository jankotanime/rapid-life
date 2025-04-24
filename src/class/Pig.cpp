#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pig.hpp"
#include <cstdlib>
#include <math.h>
#include <forward_list>

Pig::Pig(int x, int y, int s, int v) : Animal(x, y, s, v) {
  speed = 0.1;
  shape.setFillColor(sf::Color(250, 200, 220));
}

void Pig::chooseDetractor(std::forward_list<Carrot>& carrots) {
  attractors = std::forward_list<std::shared_ptr<Object>>();
  repulsers = std::forward_list<std::shared_ptr<Object>>();
  for (Carrot& carrot : carrots) {
    attractors.push_front(std::shared_ptr<Object>(&carrot, [](Object*){}));
  }
  findDirection();
}