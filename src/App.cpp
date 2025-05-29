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
  Bear bear = Bear(400, 400, 15, 120);
  Pig pig = Pig(600, 400, 10, 150);
  Rabbit rabbit = Rabbit(800, 200, 5, 80);
  Carrot carrot = Carrot(500, 400, 3);
  map = Map(App::mapWIDTH, App::mapHEIGHT);
  x = 0;
  y = 0;
  zoom = 1;

  animals.push_front(bear);
  animals.push_front(pig);
  animals.push_front(rabbit);
  fruits.push_front(carrot);

  pig = Pig(700, 700, 9, 140);
  animals.push_front(pig);

  pig = Pig(1000, 100, 10, 140);
  animals.push_front(pig);

  pig = Pig(900, 900, 10, 140);
  animals.push_front(pig);

  initial = false;
}

void App::close() {
  animals.clear();
  fruits.clear();
  corpses.clear();
  window.clear();
  window.close();
}
