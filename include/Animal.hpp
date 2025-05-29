#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include <forward_list>
#include <memory>
#include "./enum/Species.hpp"

class Animal : public Object {
  public:
  Animal(int, int, int, int);
  void drawVision(sf::RenderWindow&, int, int, int, int, double);
  void chooseDetractor(std::forward_list<Animal>&, std::forward_list<Fruit>&);
  void findDirection(int, int);
  void move(float);
  Species getSpecies();
  protected:
  Species species;
  double direction;
  double speed;
  std::forward_list<std::shared_ptr<Object>> attractors;
  std::forward_list<std::shared_ptr<Object>> repulsers;
  std::forward_list<Species> attractorSpecies;
  std::forward_list<Species> detractorSpecies;
  sf::CircleShape visionShape;
  int vision;
  bool run = false;
};

#endif