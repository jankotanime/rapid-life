#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>

class Object {
  public:
    Object(int, int, int);
    void draw(sf::RenderWindow&, int, int, int, int, double);
    sf::CircleShape shape;
    void aging();

    int getX();
    int getY();
    int getSize();
    bool isAlive();
    void kill();
    std::string getId();

    bool operator==(Object&);
  
  protected:
    std::string id;
    int x;
    int y;
    int size;
    int age = 0;
    bool alive = true;
};

#endif