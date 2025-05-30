#include "App.hpp"
#include <iostream>
#include <math.h>

void App::findingObject() {
  if (findList == nullptr) {
    findingList();
    if (findList == nullptr) return;
  }
  if (find == nullptr) {
    find = std::shared_ptr<Object>(&findList.get()->front(), [](Object*){});
  }
  bool returnNext = false;
  for (Object& object : *findList) {
    if (returnNext) {
      find = std::shared_ptr<Object>(&object, [](Object*){});
      return;
    }
    returnNext = object.getId() == find->getId();
  }
  find = std::shared_ptr<Object>(&findList.get()->front(), [](Object*){});
}

void App::findingList() {
  if (!animals.empty() && findList == nullptr) {
    findList = std::make_shared<ObjectListImpl<Animal>>(&animals);
  } else if (!fruits.empty() && ((animals.empty() && findList == nullptr) ||
    findList->get_raw_ptr() == std::make_shared<ObjectListImpl<Animal>>(&animals)->get_raw_ptr())) {
    findList = std::make_shared<ObjectListImpl<Fruit>>(&fruits);
  } else if (!corpses.empty() && ((fruits.empty() 
    && findList->get_raw_ptr() == std::make_shared<ObjectListImpl<Animal>>(&animals)->get_raw_ptr())
    || findList->get_raw_ptr() == std::make_shared<ObjectListImpl<Fruit>>(&fruits)->get_raw_ptr())) {
    findList = std::make_shared<ObjectListImpl<Corpse>>(&corpses);
  } else {
    find = nullptr;
    findList = nullptr;
    return;
  }
  
  if (findList->begin() != findList->end()) {
    find = std::shared_ptr<Object>(&findList.get()->front(), [](Object*){});
    return;
  }
  find = nullptr;
}

void App::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) close();
    if (event.type == sf::Event::KeyPressed) {
      if (menu) {
        switch (event.key.code) {
          case sf::Keyboard::Space: initial = true; break;
          default:
            break;
        }
      }
      if (start) {
        switch (event.key.code) {
          case sf::Keyboard::F: findingObject(); break;
          case sf::Keyboard::T: findingList(); break;
          case sf::Keyboard::Left: x+=5/zoom; break;
          case sf::Keyboard::Right: x-= 5/zoom; break;
          case sf::Keyboard::Up: y+=5/zoom; break;
          case sf::Keyboard::Down: y-=5/zoom; break;
          case sf::Keyboard::PageUp: if (zoom < 2) {
            zoom+=0.1;
            x-=round(0.05*WIDTH-x*0.1);
            y-=round(0.05*HEIGHT-y*0.1);
          } break;
          case sf::Keyboard::PageDown: if (zoom > 0.3) {
            zoom-=0.1;
            x+=round(0.05*WIDTH-x*0.1);
            y+=round(0.05*HEIGHT-y*0.1);
          } break;
          case sf::Keyboard::Space: pause = !pause; break;
          case sf::Keyboard::Backspace: debug.show(); break;
          case sf::Keyboard::V: vision = !vision; break;
          case sf::Keyboard::R: range = !range; break;
          default:
          break;
        }
      }
    }
  }
}