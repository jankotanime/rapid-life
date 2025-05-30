#include <SFML/Graphics.hpp>
#include <iostream>
#include "Shroom.hpp"

Shroom::Shroom(int x, int y, int s, std::forward_list<std::string> b) : Fruit(x, y, s, 500, b) {
  shape.setFillColor(sf::Color(0, 0, 0));
  species = Shrooms;
}

void Shroom::aging() {
  age++;
  if (rand() % (20 - age) == 0) alive = false;
}

void Shroom::reproduce(std::forward_list<std::unique_ptr<Fruit>>& fruits, 
std::forward_list<Corpse>& corpses, Map map) {
  for (Corpse& corpse : corpses) {
    double dx = corpse.getX() - x;
    double dy = corpse.getY() - y;
    double distance = dx * dx + dy * dy;
    if (distance < (range * range)) {
      corpse.kill();
      std::forward_list<std::string> newBloodline = bloodline;
      newBloodline.push_front(id);
      fruits.push_front(std::make_unique<Shroom>(corpse.getX(), corpse.getY(), corpse.getSize(), newBloodline));
      return;
    }
  }
}
