#ifndef CORPSE_HPP
#define CORPSE_HPP

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Corpse : public Object {
  public:
    Corpse(int, int, int, std::forward_list<std::string>);
    void aging() override;
};

#endif