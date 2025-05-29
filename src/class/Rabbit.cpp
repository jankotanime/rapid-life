#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rabbit.hpp"
#include <cstdlib>
#include <math.h>

Rabbit::Rabbit(int x, int y, int s, int v) : Animal(x, y, s, v) {
  speed = 0.15;
  shape.setFillColor(sf::Color(200, 200, 150));
  species = Rabbits;
  attractorSpecies = {Carrots};
  repulsersSpecies = {};
  repulsersBiomes = {Water};
}
