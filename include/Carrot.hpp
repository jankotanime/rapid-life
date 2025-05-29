#ifndef CARROT_HPP
#define CARROT_HPP

#include <SFML/Graphics.hpp>
#include "Fruit.hpp"

class Carrot : public Fruit {
  public:
  Carrot(int, int, int);
  void aging() override;
  void reproduce(std::forward_list<std::unique_ptr<Fruit>>&, Map) override;
  protected:
};

#endif