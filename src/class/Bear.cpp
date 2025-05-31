#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bear.hpp"
#include <cstdlib>
#include <math.h>

template<typename T>
bool includeInForwardList(std::forward_list<T>, T);

Bear::Bear(int x, int y, std::forward_list<std::string> b) : Animal(x, y, 12, 120, b) {
  speed = 0.12;
  shape.setFillColor(sf::Color(100, 80, 30));
  species = Bears;
  attractorSpecies = {Berries, Carrots, Shrooms};
  repulsersSpecies = {};
  repulsersBiomes = {Water, Savanna};
}

void Bear::breed(std::forward_list<std::unique_ptr<Animal>>& animals) {
  if (wantToBreed) {
    if (!includeInForwardList(attractorSpecies, species)) {
      attractorSpecies.push_front(species);
    }
    for (auto& animal : animals) {
      if (animal->getSpecies() == species && animal-> getId() != id && animal->breedable()
      && animal->getX() - x < 3 && x - animal->getX() < 3
      && y - animal->getY() < 3 && animal->getY() - y < 3) {
        std::forward_list<std::string> newBloodline = bloodline;
        newBloodline.push_front(id);
        newBloodline.push_front(animal->getId());
        animals.push_front(std::make_unique<Bear>(x, y, newBloodline));
        wantToBreed = false;
        animal->breeded();
        attractorSpecies.remove(species);
        return;
      }
    }
  }
}

void Bear::aging() {
  age++;
  lastEaten++;
  if (lastEaten > 8) alive = false;
  if (age > 5 && age % 3 == 0) wantToBreed = true;
  if (rand() % (50 - age) == 0) alive = false;
}