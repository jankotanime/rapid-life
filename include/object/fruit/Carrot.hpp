#ifndef CARROT_HPP
#define CARROT_HPP

#include <SFML/Graphics.hpp>
#include "./../Fruit.hpp"

class Carrot : public Fruit {
  public:
  Carrot(int, int, std::forward_list<std::string>);
  ~Carrot() {}
  
  void aging() override;
  void reproduce(std::forward_list<std::unique_ptr<Fruit>>&, std::forward_list<Corpse>&, Map) override;
  protected:
};

#endif