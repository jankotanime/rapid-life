#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bear.hpp"
#include <cstdlib>
#include <math.h>
#define PI 3.141592654

Bear::Bear(int x, int y, int s, int v) : Animal(x, y, s, v) {
  speed = 0.1;
  shape.setRadius(s*1.f);
  shape.setFillColor(sf::Color(150, 150, 150));
  visionShape.setRadius(vision*1.f);
  visionShape.setFillColor(sf::Color(200, 100, 100, 50));
  int r = rand() % 360;
  this->direction = r;
}

