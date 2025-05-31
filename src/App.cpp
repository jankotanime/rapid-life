#include "App.hpp"
#include <iostream>
#include <math.h>
#include <utility>

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

Point App::getSpawnPoint(std::forward_list<Biome> badBiomes) {
  while (true) {
    int rX = rand() % App::mapWIDTH;
    int rY = rand() % App::mapHEIGHT;
    sf::Vector2f vector(rX, rY);
    if (!map.isPointInBiomes(badBiomes, vector)) {
      return Point{rX, rY};
    }
  }
} 


void App::init() {
  menu = false;
  start = true;
  map = Map(App::mapWIDTH, App::mapHEIGHT);
  x = 0;
  y = 0;
  zoom = 1;

  for (int i = 0; i < rand() % 6 + 5; ++i) {
    Point point = getSpawnPoint(std::forward_list{Water, Forest});
    fruits.push_front(std::make_unique<Carrot>(point.x, point.y, std::forward_list<std::string>()));
  }
  // for (int i = 0; i < rand() % 6 + 5; ++i) {
  //   Point point = getSpawnPoint(std::forward_list{Water, Forest});
  //   fruits.push_front(std::make_unique<Carrot>(point.x, point.y, std::forward_list<std::string>()));
  // }
  for (int i = 0; i < rand() % 6 + 5; ++i) {
    Point point = getSpawnPoint(std::forward_list{Water, Forest});
    fruits.push_front(std::make_unique<Shroom>(point.x, point.y, 3, std::forward_list<std::string>()));
  }
  for (int i = 0; i < rand() % 6 + 5; ++i) {
    Point point = getSpawnPoint(std::forward_list{Water, Savanna});
    animals.push_front(std::make_unique<Bear>(point.x, point.y, std::forward_list<std::string>()));
  }
  for (int i = 0; i < rand() % 6 + 5; ++i) {
    Point point = getSpawnPoint(std::forward_list{Water, Forest, Savanna});
    animals.push_front(std::make_unique<Pig>(point.x, point.y, std::forward_list<std::string>()));
  }
  for (int i = 0; i < rand() % 6 + 5; ++i) {
    Point point = getSpawnPoint(std::forward_list{Water, Forest});
    animals.push_front(std::make_unique<Rabbit>(point.x, point.y, std::forward_list<std::string>()));
  }

  initial = false;
}

void App::close() {
  animals.clear();
  fruits.clear();
  corpses.clear();
  window.clear();
  window.close();
}
