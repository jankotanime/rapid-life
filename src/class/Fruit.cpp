#include <SFML/Graphics.hpp>
#include <iostream>
#include "Fruit.hpp"

Fruit::Fruit(int x, int y, int s) : Object(x, y, s) {
  shape.setRadius(s*1.f);
  shape.setFillColor(sf::Color(200, 90, 90));
}
