#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>
#include <iostream>
#include <memory>
#include "Map.hpp"
#include "./object/Fruit.hpp"
#include "./object/Animal.hpp"
#include "./object/Corpse.hpp"
#include "./method/FindList.hpp"
#include "./method/Debug.hpp"

struct Point { int x, y; };

class App {
public:
int HEIGHT = 600;
int mapWIDTH = 2000; // best 2000 - 4000
int mapHEIGHT = 2000; // best 2000 - 4000
bool menu = true;
int WIDTH = 800;
  bool start = false;
  bool initial = false;
  bool pause = false;
  bool vision = false;
  bool range = false;
  int updateTick = 1;
  std::shared_ptr<Object> find = nullptr;
  std::shared_ptr<ObjectList> findList = nullptr;
  int x, y;
  double zoom;
  std::forward_list<std::unique_ptr<Animal>> animals;
  std::forward_list<std::unique_ptr<Fruit>> fruits;
  std::forward_list<Corpse> corpses;
  App(sf::ContextSettings, std::string);
  void run();
  
  private:
  unsigned int frameCount = 0;
  float fps = 0.0f;
  sf::Clock fpsClock;
  Point getSpawnPoint(std::forward_list<Biome>);
  void processEvents();
  void update(sf::Time);
  void render();
  void init();
  template<typename T>
  void aging(std::forward_list<std::unique_ptr<T>>& objects);
  template<typename T>
  void checkAlive(std::forward_list<std::unique_ptr<T>>& objects);
  void checkCorpseOccur(std::forward_list<Corpse>&);
  void close();
  void findingObject();
  void findingList();
  sf::RenderWindow window;
  Map map;
  Debug debug = Debug(WIDTH, HEIGHT, mapWIDTH, mapHEIGHT);
};

#endif
