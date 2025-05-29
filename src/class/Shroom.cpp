#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shroom.hpp"

Shroom::Shroom(int x, int y, int s) : Fruit(x, y, s, 500) {
  shape.setFillColor(sf::Color(200, 150, 50));
  species = Shrooms;
}
