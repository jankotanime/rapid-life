#ifndef OOBJECT_HPP
#define OOBJECT_HPP

#include <SFML/Graphics.hpp>

class Object {
  public:
    Object(int, int);
    void move(float);
    void draw(sf::RenderWindow&);
    sf::CircleShape shape;
  
  private:
    double speed = 0.04; 
    int x;
    int y;
};

#endif