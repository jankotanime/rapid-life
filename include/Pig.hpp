#ifndef PIG_HPP
#define PIG_HPP

#include <SFML/Graphics.hpp>
#include "Animal.hpp"
#include "Carrot.hpp"

class Pig : public Animal {
  public:
  Pig(int, int, int, int);
  void chooseDetractor(std::forward_list<Carrot>&);
};

#endif