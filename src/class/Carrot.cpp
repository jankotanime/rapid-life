#include <SFML/Graphics.hpp>
#include <iostream>
#include "Carrot.hpp"

Carrot::Carrot(int x, int y, std::forward_list<std::string> b) : Fruit(x, y, 5, 300, b) {
  shape.setFillColor(sf::Color(200, 150, 50));
  species = Carrots;
  badBiomes = {Water, Forest};
}

void Carrot::aging() {
  age++;
  if (rand() % (2 - age) == 0) alive = false;
}

void Carrot::reproduce(std::forward_list<std::unique_ptr<Fruit>>& fruits, std::forward_list<Corpse>&, Map map) {
  while (true) {
    int newX = x + (rand() % (2 * range + 1)) - range;
    int newY = y + (rand() % (2 * range + 1)) - range;
    sf::Vector2f vector(newX, newY);
    if (newX >= 0 && newX < map.getBorderX() && newY >= 0 && newY < map.getBorderY() 
    && !map.isPointInBiomes(badBiomes, vector)) {
      std::forward_list<std::string> newBloodline = bloodline;
      newBloodline.push_front(id);
      fruits.push_front(std::make_unique<Carrot>(newX, newY, newBloodline));
      return;
    }
  }
}
