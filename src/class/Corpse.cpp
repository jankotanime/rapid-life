#include <SFML/Graphics.hpp>
#include <iostream>
#include "Corpse.hpp"

Corpse::Corpse(int x, int y, int s, std::forward_list<std::string> b) : Object(x, y, s, b) {
  shape.setFillColor(sf::Color(255, 255, 255));
}

void Corpse::aging() {
  age++;
  if (rand() % (5 - age) == 0) alive = false;
}