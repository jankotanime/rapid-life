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
      for (auto& animal : animals) animal->drawVision(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
    if (range) {
      for (auto& fruit : fruits) fruit->drawRange(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
    for (auto& animal : animals) animal->draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    for (auto& fruit : fruits) fruit->draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    for (Corpse& corpse : corpses) corpse.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    if (find != nullptr) {
      paintFindObject(window, find, x, y, mapWIDTH, mapHEIGHT, zoom);
      paintObjectStats(window, find);
    }
  }
  frameCount++;
  if (fpsClock.getElapsedTime().asSeconds() >= 1.0f) {
    fps = frameCount / fpsClock.getElapsedTime().asSeconds();
    frameCount = 0;
    fpsClock.restart();
  }
  if (debug.getShown()) {
    debug.paintMouseCords(window, map, x, y, zoom, fps);
  }
  window.display();
}