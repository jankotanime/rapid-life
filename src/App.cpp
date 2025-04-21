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
  Rabbit rabbit = Rabbit(800, 200, 5, 80);
  Carrot carrot = Carrot(500, 400, 3);
  map = Map(App::mapWIDTH, App::mapHEIGHT);
  x = 0;
  y = 0;
  zoom = 1;

  bears.push_front(bear);
  pigs.push_front(pig);
  rabbits.push_front(rabbit);
  carrots.push_front(carrot);

  initial = false;
}

void App::close() {
  bears.clear();
  pigs.clear();
  rabbits.clear();
  carrots.clear();
  corpses.clear();
  window.clear();
  window.close();
}

void App::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) close();
    if (event.type == sf::Event::KeyPressed) {
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
          case sf::Keyboard::Backspace: debug = !debug; break;
          default:
          break;
        }
      }
    }
  }
}

template<typename T>
std::forward_list<T> App::aging(std::forward_list<T> objects) {
  std::forward_list<T> newObjects;
  for (T object : objects) {
    if (object.aging()) {
      Corpse corpse = Corpse(object.getX(), object.getY(), object.getSize());
      corpses.push_front(corpse);
    } else {
      newObjects.push_front(object);
    }
  }
  return newObjects;
}

void App::update(sf::Time deltaTime) {
  if (initial) {
    init();
  }
  for (Bear& bear : bears) bear.chooseDetractor();
  for (Rabbit& rabbit : rabbits) rabbit.chooseDetractor(carrots);
  for (Pig& pig : pigs) pig.chooseDetractor(carrots);
  for (Bear& bear : bears) Object* eat = bear.eat();
  for (Rabbit& rabbit : rabbits) rabbit.eat();
  for (Pig& pig : pigs) pig.eat();
  for (Animal& animal : bears) animal.move(deltaTime.asMilliseconds());
  for (Animal& animal : pigs) animal.move(deltaTime.asMilliseconds());
  for (Animal& animal : rabbits) animal.move(deltaTime.asMilliseconds());
  if (updateTick % 40 == 0) {
    // ? sekunda
  }
  if (updateTick % 200 == 0) {
    // ? rok w symulatorze
    carrots = aging(carrots);
    bears = aging(bears);
    pigs = aging(pigs);
    rabbits = aging(rabbits);

    Carrot carrot = Carrot(rand() % mapWIDTH, rand() % mapHEIGHT, 3);
    carrots.push_front(carrot);
  }
  if (updateTick % 20000 == 0) {
    // ? 100 lat w symulatorze
    updateTick = 1;
  } else {
    updateTick++;
  }
}

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
