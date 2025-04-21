#include <SFML/Graphics.hpp>
#include <iostream>
#include "Corpse.hpp"

Corpse::Corpse(int x, int y, int s) : Object(x, y, s) {
  shape.setFillColor(sf::Color(255, 255, 255));
}
