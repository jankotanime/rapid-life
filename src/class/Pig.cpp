#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pig.hpp"
#include <cstdlib>
#include <math.h>

Pig::Pig(int x, int y, int s, int v) : Animal(x, y, s, v) {
  speed = 0.1;
  shape.setFillColor(sf::Color(250, 200, 220));
}
