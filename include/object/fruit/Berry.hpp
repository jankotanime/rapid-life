#ifndef BERRY_HPP
#define BERRY_HPP

#include <SFML/Graphics.hpp>
#include "./../Fruit.hpp"

class Berry : public Fruit {
  public:
  Berry(int, int, std::forward_list<std::string>);
  ~Berry() {}
  
  void aging() override;
  void reproduce(std::forward_list<std::unique_ptr<Fruit>>&, std::forward_list<Corpse>&, Map) override;
  protected:
};

#endif