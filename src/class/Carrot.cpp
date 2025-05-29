#include <SFML/Graphics.hpp>
#include <iostream>
#include "Carrot.hpp"

Carrot::Carrot(int x, int y, int s) : Fruit(x, y, s, 300) {
  shape.setFillColor(sf::Color(200, 150, 50));
  species = Carrots;
}
