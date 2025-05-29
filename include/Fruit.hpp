#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "./enum/Species.hpp"

class Fruit : public Object {
  public:
    Fruit(int, int, int);
    Species getSpecies();
  protected:
    Species species;
};

#endif