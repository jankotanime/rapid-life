#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

class Object {
  public:
    Object(int, int, int);
    void draw(sf::RenderWindow&, int, int, int, int);
    sf::CircleShape shape;
  
  protected:
    int x;
    int y;
    int size;
};

#endif