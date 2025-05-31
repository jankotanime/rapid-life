#ifndef LYNX_HPP
#define LYNX_HPP

#include <SFML/Graphics.hpp>
#include "Animal.hpp"

class Lynx : public Animal {
  public:
  Lynx(int, int, std::forward_list<std::string>);
  ~Lynx() {}

  void aging() override;
  void breed(std::forward_list<std::unique_ptr<Animal>>&) override;
  private:
};

#endif