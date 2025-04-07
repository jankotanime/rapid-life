#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Animal : public Object {
  public:
  Animal(int, int, int);
  void change_direction(int);
  void move(float);
  double direction; 
  double speed = 0.1;
  private:
  bool run = false;
};

#endif