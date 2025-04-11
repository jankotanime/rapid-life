#include <SFML/Graphics.hpp>
#include <iostream>
#include "Carrot.hpp"

Carrot::Carrot(int x, int y, int s) : Fruit(x, y, s) {
  shape.setFillColor(sf::Color(200, 150, 50));
}
