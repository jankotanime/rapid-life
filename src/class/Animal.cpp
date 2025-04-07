#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animal.hpp"
#include <cstdlib>
#include <math.h>
#define PI 3.141592654

Animal::Animal(int x, int y, int s) : Object(x, y, s) {
  shape.setRadius(s*1.f);
  shape.setFillColor(sf::Color(150, 150, 120));
  int r = rand() % 360;
  this->direction = r;
}

void Animal::move(float delta) {
  int r = rand() % 21;
  change_direction(r);
  x += 0.5*round(delta*speed*cos((direction*PI)/180));
  y += 0.5*round(delta*speed*sin((direction*PI)/180));
}

void Animal::change_direction(int r) {
  direction += r - 10;
}
