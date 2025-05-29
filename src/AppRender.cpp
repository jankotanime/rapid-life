#include "App.hpp"
#include <iostream>

void context_paint(sf::RenderWindow&, int, int);
void menu_paint(sf::RenderWindow&, int, int);
void paintObjectStats(sf::RenderWindow&, std::shared_ptr<Object>);
void paintFindObject(sf::RenderWindow&, std::shared_ptr<Object>, int, int, int, int, double);

void App::render() {
  context_paint(window, App::WIDTH, App::HEIGHT);
  if (menu) menu_paint(window, App::WIDTH, App::HEIGHT);
  if (start) {
    map.draw(window, x, y, zoom);
    if (vision) {
      for (Animal& animal : animals) animal.drawVision(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
    if (debug.getShown()) {
      Biome biome = map.getCordsChunk(window, 0, 0, x, y, zoom);
      debug.paintMouseCords(window, x, y, zoom, biome);
    }
    if (find != nullptr) {
      paintObjectStats(window, find);
    }
    for (Animal& animal : animals) animal.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    for (Fruit& fruit : fruits) fruit.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    for (Corpse& corpse : corpses) corpse.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    if (find != nullptr) {
      paintFindObject(window, find, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
  }

  window.display();
}