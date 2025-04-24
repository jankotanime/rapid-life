#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>

class Object {
  public:
    Object(int, int, int);
    void draw(sf::RenderWindow&, int, int, int, int, double);
    sf::CircleShape shape;
    bool aging();

    int getX();
    int getY();
    int getSize();
    void kill();
  
  protected:
    int x;
    int y;
    int size;
    int age = 0;
};

#endif