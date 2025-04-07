#include "App.hpp"
#include <iostream>

App::App(sf::ContextSettings s, std::string name) : window(sf::VideoMode(App::WIDTH, App::HEIGHT), name, sf::Style::Default, s) {
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
  Animal object1 = Animal(400, 400, 6);
  Animal object2 = Animal(400, 400, 6);
  Fruit fruit = Fruit(500, 400, 3);
  map = Map(App::mapWIDTH, App::mapHEIGHT);
  x = 0;
  y = 0;

  animals.push_front(object1);
  animals.push_front(object2);
  fruits.push_front(fruit);

  initial = false;
}

void App::close() {
  animals.clear();
  fruits.clear();
  window.clear();
  window.close();
}

void App::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) close();
    if (menu) {
      switch (event.key.code) {
        case sf::Keyboard::Space: initial = true; break;
        default:
          break;
      }
    }
    if (start) {
      switch (event.key.code) {
        case sf::Keyboard::Space:
        std::cout<< "space" << std::endl;       
        break;
        case sf::Keyboard::Left: x--; break;
        case sf::Keyboard::Right: x++; break;
        case sf::Keyboard::Up: y--; break;
        case sf::Keyboard::Down: y++; break;
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
  for (Animal& animal : animals) {
    animal.move(deltaTime.asMilliseconds());
  }
}

void App::render() {
  context_paint(window, App::WIDTH, App::HEIGHT);
  if (menu) menu_paint(window, App::WIDTH, App::HEIGHT);
  if (start) {
    map.draw(window, x, y);
    for (Object& object : animals) {
      object.draw(window, x, y, mapWIDTH, mapHEIGHT);
    }
    for (Object& object : fruits) {
      object.draw(window, x, y, mapWIDTH, mapHEIGHT);
    }
  }

  window.display();
}
