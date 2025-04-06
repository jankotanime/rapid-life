#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animal.hpp"

Animal::Animal(int x, int y) : Object(x, y) {
  shape.setRadius(7.f);
  shape.setFillColor(sf::Color(150, 150, 120));
}

void Animal::move(float delta) {
  x += delta*speed;
  shape.setPosition(x/10, y/10);
}
