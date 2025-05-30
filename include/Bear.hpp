#ifndef BEAR_HPP
#define BEAR_HPP

#include <SFML/Graphics.hpp>
#include "Animal.hpp"

class Bear : public Animal {
  public:
  Bear(int, int, int, int, std::forward_list<std::string>);
  ~Bear() {}
  void breed(std::forward_list<std::unique_ptr<Animal>>&) override;
  private:
};

#endif