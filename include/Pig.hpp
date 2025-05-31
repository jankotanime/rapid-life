#ifndef PIG_HPP
#define PIG_HPP

#include <SFML/Graphics.hpp>
#include "Animal.hpp"
#include "Carrot.hpp"

class Pig : public Animal {
  public:
  Pig(int, int, std::forward_list<std::string>);
  ~Pig() {}

  void aging() override;
  void breed(std::forward_list<std::unique_ptr<Animal>>&) override;

};

#endif