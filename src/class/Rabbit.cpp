#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rabbit.hpp"
#include <cstdlib>
#include <math.h>

Rabbit::Rabbit(int x, int y, int s, int v) : Animal(x, y, s, v) {
  speed = 0.15;
  shape.setFillColor(sf::Color(200, 200, 150));
}

void Rabbit::chooseDetractor(std::forward_list<Carrot>& carrots) {
  attractors = std::forward_list<std::shared_ptr<Object>>();
  repulsers = std::forward_list<std::shared_ptr<Object>>();
  for (Carrot& carrot : carrots) {
    attractors.push_front(std::shared_ptr<Object>(&carrot, [](Object*){}));
  }
}
