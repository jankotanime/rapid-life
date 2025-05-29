#include "App.hpp"
#include <iostream>
#include <math.h>

template<typename T>
void App::aging(std::forward_list<T> objects) {
  for (T& object : objects) {
    object.aging();
  }
}

template<typename T>
void App::checkAlive(std::forward_list<T>& objects) {
  objects.remove_if([this](T& object) {
    if (!object.isAlive()) {
      Corpse corpse(object.getX(), object.getY(), object.getSize());
      corpses.push_front(corpse);
      if (find != nullptr && find.get()->getId() == object.getId()) { find = nullptr; }
      return true;
    }
    return false;
  });
}

void App::update(sf::Time deltaTime) {
  if (initial) {
    init();
  }
  if (start && !pause) {
    for (Animal& animal : animals) animal.chooseDetractor(animals, fruits);

    for (Animal& animal : animals) animal.findDirection(mapWIDTH, mapHEIGHT);
    
    checkAlive(animals);

    for (Animal& animal : animals) animal.move(deltaTime.asMilliseconds());

    if (updateTick % 40 == 0) {
      // ? sekunda
    }
    if (updateTick % 200 == 0) {
      // ? rok w symulatorze
      aging(animals);
      
      Carrot carrot = Carrot(rand() % mapWIDTH, rand() % mapHEIGHT, 3);
      fruits.push_front(carrot);
    }
    if (updateTick % 20000 == 0) {
      // ? 100 lat w symulatorze
      updateTick = 1;
    } else {
      updateTick++;
    }
  }
}
  