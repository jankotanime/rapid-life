#include "App.hpp"
#include <iostream>

App::App() : window(sf::VideoMode(App::WIDTH, App::HEIGHT), "Rapid life", sf::Style::Default) {
  window.setFramerateLimit(60);
}

void context_paint(sf::RenderWindow&, int, int);
void menu_paint(sf::RenderWindow&, int, int);

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
  Object object1 = Object(100, 200);
  Object object2 = Object(200, 100);

  objects.push_front(object1);
  objects.push_front(object2);

  initial = false;
}

void App::close() {
  objects.clear();
  window.clear();
  window.close();
}

void App::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) close();
    if (menu) {
      switch (event.key.code) {
        case sf::Keyboard::Space:
          initial = true;
          break;
        default:
          break;
      }
    }
    if (start) {
      switch (event.key.code) {
        case sf::Keyboard::Space:
        std::cout<< "space" << std::endl;
        break;
        default:
        break;
      }
    }
  }
}

void App::update(sf::Time deltaTime) {
  if (initial) {
    init();
  }
  for (Object& object : objects) {
    object.move(deltaTime.asMilliseconds());
  }
}

void App::render() {
  context_paint(window, App::WIDTH, App::HEIGHT);
  if (menu) menu_paint(window, App::WIDTH, App::HEIGHT);
  if (start) {
    for (Object& object : objects) {
      object.draw(window);
    }
  }

  window.display();
}
