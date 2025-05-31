#include <SFML/Graphics.hpp>
#include <iostream>
#include "object/fruit/Berry.hpp"

Berry::Berry(int x, int y, std::forward_list<std::string> b) : Fruit(x, y, 5, 800, b) {
  shape.setFillColor(sf::Color(200, 80, 230));
  species = Carrots;
  badBiomes = {Water, Savanna};
}

void Berry::aging() {
  age++;
  if (rand() % (8 - age) == 0) alive = false;
}

void Berry::reproduce(std::forward_list<std::unique_ptr<Fruit>>& fruits, std::forward_list<Corpse>&, Map map) {
  if (rand() % 3 < 2) return;
  while (true) {
    int newX = x + (rand() % (2 * range + 1)) - range;
    int newY = y + (rand() % (2 * range + 1)) - range;
    sf::Vector2f vector(newX, newY);
    if (newX >= 0 && newX < map.getBorderX() && newY >= 0 && newY < map.getBorderY() 
    && !map.isPointInBiomes(badBiomes, vector)) {
      std::forward_list<std::string> newBloodline = bloodline;
      newBloodline.push_front(id);
      fruits.push_front(std::make_unique<Berry>(newX, newY, newBloodline));
      return;
    }
  }
}
