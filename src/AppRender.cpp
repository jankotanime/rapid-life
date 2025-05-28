#include "App.hpp"
#include <iostream>

void context_paint(sf::RenderWindow&, int, int);
void menu_paint(sf::RenderWindow&, int, int);
void paintObjectStats(sf::RenderWindow&, std::shared_ptr<Object>);
void paintFindObject(sf::RenderWindow&, std::shared_ptr<Object>, int, int, int, int, double);
void paintMouseCords(sf::RenderWindow&, int, int, int, int, int, int, double, Biome);

void App::render() {
  context_paint(window, App::WIDTH, App::HEIGHT);
  if (menu) menu_paint(window, App::WIDTH, App::HEIGHT);
  if (start) {
    map.draw(window, x, y, zoom);
    if (vision) {
      for (Animal& animal : bears) animal.drawVision(window, x, y, mapWIDTH, mapHEIGHT, zoom);
      for (Animal& animal : pigs) animal.drawVision(window, x, y, mapWIDTH, mapHEIGHT, zoom);
      for (Animal& animal : rabbits) animal.drawVision(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
    if (debug) {
      Biome biome = map.getCordsChunk(window, 0, 0, x, y, zoom);
      paintMouseCords(window, App::WIDTH, App::HEIGHT, mapWIDTH, mapHEIGHT, x, y, zoom, biome);
    }
    if (find != nullptr) {
      paintObjectStats(window, find);
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
    if (find != nullptr) {
      paintFindObject(window, find, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
  }

  window.display();
}