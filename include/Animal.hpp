#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Animal : public Object {
  public:
  Animal(int, int, int);
  void change_direction(int);
  void draw_vision(sf::RenderWindow&, int, int, int, int, double);
  void move(float);
  double direction;
  double speed = 0.1;
  private:
  sf::CircleShape visionShape;
  int vision = 100;
  bool run = false;
};

#endif