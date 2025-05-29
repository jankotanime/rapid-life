#include <SFML/Graphics.hpp>
#include <iostream>
#include "Fruit.hpp"

Fruit::Fruit(int x, int y, int s) : Object(x, y, s) {
}

Species Fruit::getSpecies() {
  return species;
}