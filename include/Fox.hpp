#ifndef FOX_HPP
#define FOX_HPP

#include <SFML/Graphics.hpp>
#include "Animal.hpp"

class Fox : public Animal {
  public:
  Fox(int, int, std::forward_list<std::string>);
  ~Fox() {}

  void aging() override;
  void breed(std::forward_list<std::unique_ptr<Animal>>&) override;
  private:
};

#endif