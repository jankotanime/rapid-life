#ifndef RABBIT_HPP
#define RABBIT_HPP

#include <SFML/Graphics.hpp>
#include "Animal.hpp"
#include "Carrot.hpp"

class Rabbit : public Animal {
  public:
  Rabbit(int, int, std::forward_list<std::string>);
  ~Rabbit() {}

  void aging() override;
  void breed(std::forward_list<std::unique_ptr<Animal>>&) override;

};

#endif