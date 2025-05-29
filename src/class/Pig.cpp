#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pig.hpp"
#include <cstdlib>
#include <math.h>
#include <forward_list>

Pig::Pig(int x, int y, int s, int v) : Animal(x, y, s, v) {
  speed = 0.13;
  shape.setFillColor(sf::Color(250, 200, 220));
  species = Pigs;
  attractorSpecies = {Carrots};
  repulsersSpecies = {Bears};
  repulsersBiomes = {Water};
}
