#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include <forward_list>

class Animal : public Object {
  public:
  Animal(int, int, int, int);
  void changeDirection(int);
  void drawVision(sf::RenderWindow&, int, int, int, int, double);
  void findDirection(std::forward_list<Object>, std::forward_list<Object>);
  void move(float);
  protected:
  double direction;
  double speed;
  sf::CircleShape visionShape;
  int vision;
  bool run = false;

};

#endif