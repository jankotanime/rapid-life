#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Animal : public Object {
  public:
  Animal(int, int);
  void move(float);
  private:
  double speed = 0.04; 
};

#endif