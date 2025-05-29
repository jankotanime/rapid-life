#ifndef Shroom_HPP
#define Shroom_HPP

#include <SFML/Graphics.hpp>
#include "Fruit.hpp"

class Shroom : public Fruit {
  public:
  Shroom(int, int, int);
  void reproduce(std::forward_list<std::unique_ptr<Fruit>>&, Map) override;
  protected:
};

#endif