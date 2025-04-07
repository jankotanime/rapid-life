#ifndef FRUIT_HPP
#define FRUIT_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Fruit : public Object {
  public:
    Fruit(int, int, int);
};

#endif