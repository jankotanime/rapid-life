#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>
#include "./enum/Species.hpp"

class Object {
  public:
    Object(int, int, int, std::forward_list<std::string>);
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
    std::forward_list<std::string> getBloodline();
  
  protected:
    Species species;
    std::string id;
    int x;
    int y;
    int size;
    int age = 0;
    bool alive = true;
    std::forward_list<std::string> bloodline;
};

#endif