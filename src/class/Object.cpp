#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.hpp"

Object::Object(int x, int y) : x(x), y(y) {}

void Object::draw(sf::RenderWindow& window) {
  shape.setPosition(x/5, y/5);
  window.draw(shape);
}