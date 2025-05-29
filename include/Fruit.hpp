#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "./enum/Species.hpp"
#include "Map.hpp"

class Fruit : public Object {
  public:
    Fruit(int, int, int, int);
    Species getSpecies();
    void drawRange(sf::RenderWindow&, int, int, int, int, double);
    virtual void reproduce(std::forward_list<std::unique_ptr<Fruit>>&, Map) = 0;
  protected:
    std::forward_list<Biome> badBiomes;
    sf::CircleShape rangeShape;
    Species species;
    int range;
};

#endif