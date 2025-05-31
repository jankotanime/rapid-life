#include <SFML/Graphics.hpp>
#include <iostream>
#include "object/animal/Beaver.hpp"
#include <cstdlib>
#include <math.h>

template<typename T>
bool includeInForwardList(std::forward_list<T>, T);

Beaver::Beaver(int x, int y, std::forward_list<std::string> b) : Animal(x, y, 6, 100, b) {
  speed = 0.15;
  shape.setFillColor(sf::Color(120, 100, 80));
  species = Beavers;
  attractorSpecies = {Carrots, Berries};
  repulsersSpecies = {Foxes, Lynxes, Bears};
  repulsersBiomes = {Savanna};
}

void Beaver::breed(std::forward_list<std::unique_ptr<Animal>>& animals) {
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
        animals.push_front(std::make_unique<Beaver>(x, y, newBloodline));
        wantToBreed = false;
        animal->breeded();
        attractorSpecies.remove(species);
        return;
      }
    }
  }
}

void Beaver::aging() {
  age++;
  lastEaten++;
  if (lastEaten > 8) alive = false;
  if (age > 5 && age % 2 == 0) wantToBreed = true;
  if (rand() % (20 - age) == 0) alive = false;
}