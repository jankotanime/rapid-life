#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pig.hpp"
#include <cstdlib>
#include <math.h>
#include <forward_list>

template<typename T>
bool includeInForwardList(std::forward_list<T>, T);

Pig::Pig(int x, int y, int s, int v, std::forward_list<std::string> b) : Animal(x, y, s, v, b) {
  speed = 0.13;
  shape.setFillColor(sf::Color(250, 200, 220));
  species = Pigs;
  attractorSpecies = {Carrots};
  repulsersSpecies = {Bears};
  repulsersBiomes = {Water};
}

void Pig::breed(std::forward_list<std::unique_ptr<Animal>>& animals) {
  if (wantToBreed) {
    if (!includeInForwardList(attractorSpecies, species)) {
      attractorSpecies.push_front(species);
    }
    for (auto& animal : animals) {
      if (animal->getSpecies() == species && animal->getId() != id && animal->breedable()
      && animal->getX() - x < 3 && x - animal->getX() < 3
      && y - animal->getY() < 3 && animal->getY() - y < 3) {
        std::forward_list<std::string> newBloodline = bloodline;
        newBloodline.push_front(id);
        newBloodline.push_front(animal->getId());
        animals.push_front(std::make_unique<Pig>(x, y, size, vision, newBloodline));
        wantToBreed = false;
        animal->breeded();
        attractorSpecies.remove(species);
        return;
      }
    }
  }
};
