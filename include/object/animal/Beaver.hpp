#ifndef BEAVER_HPP
#define BEAVER_HPP

#include <SFML/Graphics.hpp>
#include "./../Animal.hpp"

class Beaver : public Animal {
  public:
  Beaver(int, int, std::forward_list<std::string>);
  ~Beaver() {}

  void aging() override;
  void breed(std::forward_list<std::unique_ptr<Animal>>&) override;
  private:
};

#endif