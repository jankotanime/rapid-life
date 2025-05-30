#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rabbit.hpp"
#include <cstdlib>
#include <math.h>

template<typename T>
bool includeInForwardList(std::forward_list<T>, T);

Rabbit::Rabbit(int x, int y, int s, int v) : Animal(x, y, s, v) {
  speed = 0.15;
  shape.setFillColor(sf::Color(200, 200, 150));
  species = Rabbits;
  attractorSpecies = {Carrots};
  repulsersSpecies = {};
  repulsersBiomes = {Water};
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
        animals.push_front(std::make_unique<Rabbit>(x, y, size, vision));
        wantToBreed = false;
        animal->breeded();
        attractorSpecies.remove(species);
        return;
      }
    }
  }
};