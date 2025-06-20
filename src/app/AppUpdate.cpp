#include "App.hpp"
#include <iostream>
#include <math.h>

template<typename T>
void App::aging(std::forward_list<std::unique_ptr<T>>& objects) {
  for (auto& object : objects) {
    object->aging();
  }
}

void agingCorpses(std::forward_list<Corpse>& corpses) {
  for (auto& corpse : corpses) {
    corpse.aging();
  }
}

template<typename T>
void App::checkAlive(std::forward_list<std::unique_ptr<T>>& objects) {
  objects.remove_if([this](std::unique_ptr<T>& object) {
    if (!object->isAlive()) {
      if (find.get() == object.get()) find = nullptr;
      if (object->getSpecies() != Shrooms) {
        corpses.push_front(Corpse(
        object->getX(), object->getY(), object->getSize(), object->getBloodline()));
      } 
      return true;
    }
    return false;
  });
}

void App::checkCorpseOccur(std::forward_list<Corpse>& corpses) {
  corpses.remove_if([this](Corpse& corpse) {
    if (!corpse.isAlive()) {
      if (find && find.get() == &corpse) find = nullptr;
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
    for (auto& animal : animals) animal->chooseDetractor(animals, fruits);
    for (auto& animal : animals) animal->findDirection(mapWIDTH, mapHEIGHT, map);

    for (auto& animal : animals) animal->breed(animals);
    
    checkAlive(animals);
    checkAlive(fruits);
    checkCorpseOccur(corpses);

    for (auto& animal : animals) animal->move(deltaTime.asMilliseconds());

    if (updateTick % 40 == 0) {
      // ? sekunda
    }
    if (updateTick % 200 == 0) {
      // ? rok w symulatorze
      aging(animals);
      aging(fruits);
      agingCorpses(corpses);
      for (auto& fruit : fruits) fruit->reproduce(fruits, corpses, map);
    }
    if (updateTick % 600 == 0) {
      // ? 3 lata w symulatorze
    }
    if (updateTick % 20000 == 0) {
      // ? 100 lat w symulatorze
      updateTick = 1;
    } else {
      updateTick++;
    }
  }
}
