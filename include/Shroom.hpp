#ifndef Shroom_HPP
#define Shroom_HPP

#include <SFML/Graphics.hpp>
#include "Fruit.hpp"

class Shroom : public Fruit {
  public:
  Shroom(int, int, int, std::forward_list<std::string>);
  ~Shroom() {}
  void aging() override;
  void reproduce(std::forward_list<std::unique_ptr<Fruit>>&, std::forward_list<Corpse>&, Map) override;
  protected:
};

#endif