#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animal.hpp"
#include <cstdlib>
#include <math.h>
#define PI 3.141592654

Animal::Animal(int x, int y) : Object(x, y) {
  shape.setRadius(7.f);
  shape.setFillColor(sf::Color(150, 150, 120));
  int r = rand() % 360;
  this->direction = r;
}

void Animal::move(float delta) {
  x += round(delta*speed*cos((direction*PI)/180));
  y += round(delta*speed*sin((direction*PI)/180));
  shape.setPosition(x, y);
  int r = rand() % 21;
  change_direction(r);
}

void Animal::change_direction(int r) {
  direction += r - 10;
}
