#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>
#include <iostream>
#include <memory>
#include "Fruit.hpp"
#include "Animal.hpp"
#include "Pig.hpp"
#include "Bear.hpp"
#include "Map.hpp"
#include "Carrot.hpp"
#include "Rabbit.hpp"
#include "Corpse.hpp"
#include "FindList.hpp"
#include "Debug.hpp"

class App {
public:
  int WIDTH = 800;
  int HEIGHT = 600;
  int mapWIDTH = 2000; // best 2000 - 4000
  int mapHEIGHT = 2000; // best 2000 - 4000
  bool menu = true;
  bool start = false;
  bool initial = false;
  bool pause = false;
  bool vision = false;
  int updateTick = 1;
  std::shared_ptr<Object> find = nullptr;
  std::shared_ptr<ObjectList> findList = nullptr;
  int x, y;
  double zoom;
  std::forward_list<Bear> bears;
  std::forward_list<Rabbit> rabbits;
  std::forward_list<Pig> pigs;
  std::forward_list<Carrot> carrots;
  std::forward_list<Corpse> corpses;
  App(sf::ContextSettings, std::string);
  void run();
  
  private:
  void processEvents();
  void update(sf::Time);
  void render();
  void init();
  template<typename T>
  void aging(std::forward_list<T> objects);
  template<typename T>
  void checkAlive(std::forward_list<T>& objects);
  void close();
  void findingObject();
  void findingList();
  sf::RenderWindow window;
  Map map;
  Debug debug = Debug(WIDTH, HEIGHT, mapWIDTH, mapHEIGHT);
};

#endif
