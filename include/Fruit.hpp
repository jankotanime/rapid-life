#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "./enum/Species.hpp"

class Fruit : public Object {
  public:
    Fruit(int, int, int, int);
    Species getSpecies();
    void drawRange(sf::RenderWindow&, int, int, int, int, double);
  protected:
    sf::CircleShape rangeShape;
    Species species;
    int range;
};

#endif