#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include <forward_list>

class Animal : public Object {
  public:
  Animal(int, int, int, int);
  void drawVision(sf::RenderWindow&, int, int, int, int, double);
  void findDirection();
  void move(float);
  Object* eat();
  protected:
  double direction;
  double speed;
  std::forward_list<Object> attractors;
  std::forward_list<Object> repulsers;
  sf::CircleShape visionShape;
  int vision;
  bool run = false;

};

#endif