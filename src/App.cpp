#include "App.hpp"
#include <iostream>
#include <math.h>

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
  Bear bear = Bear(400, 400, 15, 120);
  Pig pig = Pig(600, 400, 10, 150);
  Fruit fruit = Fruit(500, 400, 3);
  map = Map(App::mapWIDTH, App::mapHEIGHT);
  x = 0;
  y = 0;
  zoom = 1;

  animals.push_front(bear);
  animals.push_front(pig);
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
        case sf::Keyboard::Left: x+=5/zoom; break;
        case sf::Keyboard::Right: x-= 5/zoom; break;
        case sf::Keyboard::Up: y+=5/zoom; break;
        case sf::Keyboard::Down: y-=5/zoom; break;
        case sf::Keyboard::PageUp: if (zoom < 2) {
          zoom+=0.1;
          x-=round(0.05*WIDTH-x*0.1);
          y-=round(0.05*HEIGHT-y*0.1);
        } break;
        case sf::Keyboard::PageDown: if (zoom > 0.3) {
          zoom-=0.1;
          x+=round(0.05*WIDTH-x*0.1);
          y+=round(0.05*HEIGHT-y*0.1);
        } break;
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
    map.draw(window, x, y, zoom);
    for (Animal& object : animals) {
      object.draw_vision(window, x, y, mapWIDTH, mapHEIGHT, zoom);
      object.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
    for (Object& object : fruits) {
      object.draw(window, x, y, mapWIDTH, mapHEIGHT, zoom);
    }
  }

  window.display();
}
