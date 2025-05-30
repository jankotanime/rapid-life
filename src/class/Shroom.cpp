#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shroom.hpp"

Shroom::Shroom(int x, int y, int s) : Fruit(x, y, s, 500) {
  shape.setFillColor(sf::Color(250, 250, 250));
  species = Shrooms;
}

void Shroom::aging() {
  age++;
  if (rand() % (100 - age) == 0) alive = false;
}

void Shroom::reproduce(std::forward_list<std::unique_ptr<Fruit>>& fruits, 
std::forward_list<Corpse>& corpses, Map map) {
  for (Corpse& corpse : corpses) {
    if (x + (rand() % (2 * range + 1)) - range <= corpse.getX() 
    && y + (rand() % (2 * range + 1)) - range <= corpse.getY()) {
      corpse.kill();
      fruits.push_front(std::make_unique<Shroom>(corpse.getX(), corpse.getY(), corpse.getSize()));
      return;
    }
  }
}
