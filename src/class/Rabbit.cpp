#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rabbit.hpp"
#include <cstdlib>
#include <math.h>

template<typename T>
bool includeInForwardList(std::forward_list<T>, T);

Rabbit::Rabbit(int x, int y, std::forward_list<std::string> b) : Animal(x, y, 5, 100, b) {
  speed = 0.17;
  shape.setFillColor(sf::Color(180, 170, 120));
  species = Rabbits;
  attractorSpecies = {Carrots};
  repulsersSpecies = {};
  repulsersBiomes = {Water, Forest};
}

void Rabbit::breed(std::forward_list<std::unique_ptr<Animal>>& animals) {
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
        animals.push_front(std::make_unique<Rabbit>(x, y, newBloodline));
        wantToBreed = false;
        animal->breeded();
        attractorSpecies.remove(species);
        return;
      }
    }
  }
}

void Rabbit::aging() {
  age++;
  lastEaten++;
  if (lastEaten > 5) alive = false;
  if (age > 1 && age % 2 == 0) wantToBreed = true;
  if (rand() % (8 - age) == 0) alive = false;
}