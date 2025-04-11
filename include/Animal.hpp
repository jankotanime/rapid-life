#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Animal : public Object {
  public:
  Animal(int, int, int, int);
  void change_direction(int);
  void draw_vision(sf::RenderWindow&, int, int, int, int, double);
  void move(float);
  protected:
  double direction;
  double speed;
  sf::CircleShape visionShape;
  int vision;
  bool run = false;
};

#endif