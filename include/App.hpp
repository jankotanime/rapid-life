#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <forward_list>
#include <iostream>
#include "Object.hpp"
#include "Fruit.hpp"
#include "Animal.hpp"
#include "Pig.hpp"
#include "Bear.hpp"
#include "Map.hpp"
#include "Carrot.hpp"
#include "Rabbit.hpp"
#include "Corpse.hpp"
#include <memory>

struct Iterator {
  using DerefFn = Object&(*)(void*);
  using IncrFn  = void(*)(void*);
  using CmpFn   = bool(*)(void*, void*);

  void* ptr;
  DerefFn deref;
  IncrFn incr;
  CmpFn cmp;

  Object& operator*() const { return deref(ptr); }
  Iterator& operator++() { incr(ptr); return *this; }
  bool operator!=(const Iterator& other) const { return !cmp(ptr, other.ptr); }

  ~Iterator() { delete static_cast<char*>(ptr); }
};

struct ObjectList {
  virtual ~ObjectList() = default;
  virtual Object& front() = 0;
  virtual void* get_raw_ptr() const = 0;
  virtual struct Iterator begin() = 0;
  virtual struct Iterator end() = 0;
};

template<typename T>
struct ObjectListImpl : ObjectList {
  std::forward_list<T>* list;
  ObjectListImpl(std::forward_list<T>* l) : list(l) {}
  Object& front() override { return list->front(); }
  void* get_raw_ptr() const override { return static_cast<void*>(list); }
  Iterator begin() override {
    using It = typename std::forward_list<T>::iterator;
    It* it = new It(list->begin());
    return {
        it,
        [](void* p) -> Object& { return **static_cast<It*>(p); },
        [](void* p) { ++(*static_cast<It*>(p)); },
        [](void* a, void* b) -> bool { return *static_cast<It*>(a) == *static_cast<It*>(b); }
    };
}

Iterator end() override {
    using It = typename std::forward_list<T>::iterator;
    It* it = new It(list->end());
    return {
        it,
        [](void* p) -> Object& { return **static_cast<It*>(p); },
        [](void* p) { ++(*static_cast<It*>(p)); },
        [](void* a, void* b) -> bool { return *static_cast<It*>(a) == *static_cast<It*>(b); }
    };
}
};

class App {
public:
  int WIDTH = 800;
  int HEIGHT = 600;
  int mapWIDTH = 2000; // best 2000 - 4000
  int mapHEIGHT = 2000; // best 2000 - 4000
  bool menu = true;
  bool start = false;
  bool initial = false;
  bool debug = false;
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
};

#endif
