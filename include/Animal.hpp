#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include <forward_list>
#include <memory>

class Animal : public Object {
  public:
  Animal(int, int, int, int);
  void drawVision(sf::RenderWindow&, int, int, int, int, double);
  void findDirection();
  void move(float);
  protected:
  double direction;
  double speed;
  std::forward_list<std::shared_ptr<Object>> attractors;
  std::forward_list<std::shared_ptr<Object>> repulsers;
  sf::CircleShape visionShape;
  int vision;
  bool run = false;
};

#endif