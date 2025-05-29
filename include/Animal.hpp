#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"
#include "Fruit.hpp"
#include <forward_list>
#include <memory>
#include "./enum/Species.hpp"
#include "./enum/Biome.hpp"
#include "Map.hpp"

class Animal : public Object {
  public:
  Animal(int, int, int, int);
  void drawVision(sf::RenderWindow&, int, int, int, int, double);
  void chooseDetractor(std::forward_list<Animal>&, std::forward_list<Fruit>&);
  void findDirection(int, int, Map);
  void move(float);
  Species getSpecies();
  protected:
  Species species;
  double direction;
  double speed;
  std::forward_list<std::shared_ptr<Object>> attractors;
  std::forward_list<std::shared_ptr<Object>> repulsers;
  std::forward_list<Species> attractorSpecies;
  std::forward_list<Species> repulsersSpecies;
  std::forward_list<Biome> repulsersBiomes;
  sf::CircleShape visionShape;
  int vision;
  bool run = false;
};

#endif