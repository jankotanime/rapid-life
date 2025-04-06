#include <SFML/Graphics.hpp>
#include <iostream>
#include "Fruit.hpp"

Fruit::Fruit(int x, int y) : Object(x, y) {
  shape.setRadius(3.f);
  shape.setFillColor(sf::Color(200, 90, 90));
}
