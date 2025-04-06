#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.hpp"

Object::Object(int x, int y) : x(x), y(y) {}

void Object::move(float delta) {
  std::cout << delta << " , " << speed << std::endl;
  x += delta*speed;
  shape.setPosition(x/10, y/10);
}

void Object::draw(sf::RenderWindow& window) {
  shape.setRadius(3.f);
  shape.setFillColor(sf::Color(100, 250, 50));
  shape.setPosition(x/5, y/5);
  window.draw(shape);
}