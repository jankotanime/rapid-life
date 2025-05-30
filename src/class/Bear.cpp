#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bear.hpp"
#include <cstdlib>
#include <math.h>

template<typename T>
bool includeInForwardList(std::forward_list<T>, T);

Bear::Bear(int x, int y, int s, int v) : Animal(x, y, s, v) {
  speed = 0.12;
  shape.setFillColor(sf::Color(100, 80, 30));
  species = Bears;
  attractorSpecies = {};
  repulsersSpecies = {};
  repulsersBiomes = {Water};
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
        animals.push_front(std::make_unique<Bear>(x, y, size, vision));
        wantToBreed = false;
        animal->breeded();
        attractorSpecies.remove(species);
        return;
      }
    }
  }
};