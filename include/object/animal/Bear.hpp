#ifndef BEAR_HPP
#define BEAR_HPP

#include "./../Animal.hpp"

class Bear : public Animal {
  public:
  Bear(int, int, std::forward_list<std::string>);
  ~Bear() {}

  void aging() override;
  void breed(std::forward_list<std::unique_ptr<Animal>>&) override;
  private:
};

#endif