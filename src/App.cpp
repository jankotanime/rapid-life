#include "App.hpp"
#include <iostream>
#include <math.h>

App::App(sf::ContextSettings s, std::string name) : window(sf::VideoMode(App::WIDTH, App::HEIGHT), name, sf::Style::Default, s) {
  window.setFramerateLimit(60);
}

void App::run() {
  sf::Clock clock;
  sf::Time elapsed = sf::Time::Zero;
  sf::Time deltaTimeLimit = sf::seconds(0.025f);
  while (window.isOpen()) {
    elapsed += clock.restart();
    while (elapsed >= deltaTimeLimit) {
      elapsed -= deltaTimeLimit;
      update(deltaTimeLimit);
      processEvents();
    }
    render();
  }
  return;
}

void App::init() {
  menu = false;
  start = true;
  map = Map(App::mapWIDTH, App::mapHEIGHT);
  x = 0;
  y = 0;
  zoom = 1;

  // animals.push_front(std::make_unique<Bear>(400, 400, 15, 120));
  animals.push_front(std::make_unique<Pig>(600, 400, 10, 150));
  animals.push_front(std::make_unique<Pig>(900, 800, 10, 150));
  animals.push_front(std::make_unique<Pig>(1200, 1700, 10, 150));
  animals.push_front(std::make_unique<Rabbit>(800, 200, 5, 80));
  fruits.push_front(std::make_unique<Carrot>(500, 400, 3));
  fruits.push_front(std::make_unique<Carrot>(1000, 1000, 3));
  fruits.push_front(std::make_unique<Carrot>(1500, 600, 3));
  fruits.push_front(std::make_unique<Shroom>(800, 800, 3));

  initial = false;
}

void App::close() {
  animals.clear();
  fruits.clear();
  corpses.clear();
  window.clear();
  window.close();
}
