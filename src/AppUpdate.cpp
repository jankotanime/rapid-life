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
  if (start) {
    for (Bear& bear : bears) bear.chooseDetractor();
    for (Rabbit& rabbit : rabbits) rabbit.chooseDetractor(carrots);
    for (Pig& pig : pigs) pig.chooseDetractor(carrots);

    for (Bear& bear : bears) bear.findDirection(mapWIDTH, mapHEIGHT);
    for (Rabbit& rabbit : rabbits) rabbit.findDirection(mapWIDTH, mapHEIGHT);
    for (Pig& pig : pigs) pig.findDirection(mapWIDTH, mapHEIGHT);
    
    checkAlive(carrots);
    checkAlive(bears);
    checkAlive(pigs);
    checkAlive(rabbits);

    for (Animal& animal : bears) animal.move(deltaTime.asMilliseconds());
    for (Animal& animal : pigs) animal.move(deltaTime.asMilliseconds());
    for (Animal& animal : rabbits) animal.move(deltaTime.asMilliseconds());

    if (updateTick % 40 == 0) {
      // ? sekunda
    }
    if (updateTick % 200 == 0) {
      // ? rok w symulatorze
      aging(carrots);
      aging(bears);
      aging(pigs);
      aging(rabbits);
      
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
}
  