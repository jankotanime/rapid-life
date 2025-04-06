#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

class Object {
  public:
    Object(int, int);
    void draw(sf::RenderWindow&);
    sf::CircleShape shape;
  
  protected:
    int x;
    int y;
};

#endif