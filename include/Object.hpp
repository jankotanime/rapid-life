#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>
#include "./enum/Species.hpp"

class Object {
  public:
    Object(int, int, int);
    ~Object() {};
    void draw(sf::RenderWindow&, int, int, int, int, double);
    sf::CircleShape shape;
    Species getSpecies();
    virtual void aging();
    int getX();
    int getY();
    int getSize();
    bool isAlive();
    void kill();
    std::string getId();

    bool operator==(Object&);
  
  protected:
    Species species;
    std::string id;
    int x;
    int y;
    int size;
    int age = 0;
    bool alive = true;
};

#endif