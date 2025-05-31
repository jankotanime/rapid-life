#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <SFML/Graphics.hpp>
#include "./Object.hpp"
#include "./Fruit.hpp"
#include <forward_list>
#include <memory>
#include "./../enum/Biome.hpp"
#include "Map.hpp"

class Animal : public Object {
  public:
  Animal(int, int, int, int, std::forward_list<std::string>);
  virtual ~Animal() {};
  void drawVision(sf::RenderWindow&, int, int, int, int, double);
  void chooseDetractor(std::forward_list<std::unique_ptr<Animal>>&, std::forward_list<std::unique_ptr<Fruit>>&);
  void findDirection(int, int, Map);
  void move(float);
  void aging() override;
  void breeded();
  bool breedable();
  virtual void breed(std::forward_list<std::unique_ptr<Animal>>&) = 0;

  protected:
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
  bool wantToBreed = false;
  int lastEaten = 0;
};

#endif