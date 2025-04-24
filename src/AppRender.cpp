#include "App.hpp"
#include <iostream>

void context_paint(sf::RenderWindow&, int, int);
void menu_paint(sf::RenderWindow&, int, int);

void App::render() {
  context_paint(window, App::WIDTH, App::HEIGHT);
  if (menu) menu_paint(window, App::WIDTH, App::HEIGHT);
  if (start) {
    map.draw(window, x, y, zoom);
    if (debug) {
      for (Animal& animal : bears) animal.drawVision(window, x, y, mapWIDTH, mapHEIGHT, zoom);
      for (Animal& animal : pigs) animal.drawVision(window, x, y, mapWIDTH, mapHEIGHT, zoom);
      for (Animal& animal : rabbits) animal.drawVision(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
    if (find != nullptr) {
      std::cout << find->getId() << std::endl;
    }
    for (Animal& animal : bears) animal.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    for (Animal& animal : pigs) animal.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    for (Animal& animal : rabbits) animal.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    for (Object& object : carrots) {
      object.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
    for (Corpse& corpse : corpses) {
      corpse.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
  }

  window.display();
}