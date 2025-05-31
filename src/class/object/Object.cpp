#include <SFML/Graphics.hpp>
#include <iostream>
#include "object/Object.hpp"
#include <chrono>
#include <ctime>

Object::Object(int x, int y, int s, std::forward_list<std::string> b) : x(x), y(y), size(s), bloodline(b) {
  auto now = std::chrono::high_resolution_clock::now();
  auto duration = now.time_since_epoch();
  auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();

  id = std::to_string(nanos);
  shape.setRadius(s*1.f);
}

Species Object::getSpecies() {
  return species;
}

std::forward_list<std::string> Object::getBloodline() {
  return bloodline;
}

void Object::aging() {
  age++;
  if (rand() % (50 - age) == 0) alive = false;
}

int Object::getX() {
  return x;
}
int Object::getY() {
  return y;
}
int Object::getSize() {
  return size;
}
int Object::getAge() {
  return age;
}
std::string Object::getId() {
  return id;
}

bool Object::isAlive() {
  return alive;
}

void Object::kill() {
  alive = false;
}

bool Object::operator==(Object& o) {
  return id == o.getId();
};

void Object::draw(sf::RenderWindow& window, int mapX, int mapY, int mapWIDTH, int mapHEIGHT, double zoom) {
  shape.setScale({zoom*1.f, zoom*1.f});
  if (x < -size) {
    x = mapWIDTH - size;
  } else if (x > mapWIDTH - size) {
    x = -size;
  }
  if (y < -size) {
    y = mapHEIGHT - size;
  } else if (y > mapHEIGHT - size) {
    y = -size;
  }
  bool secondDraw = (x < 0 || x > mapWIDTH - 2*size || y < 0 || y > mapHEIGHT - 2 * size);
  if (secondDraw) {
    int secondDrawX = x;
    int secondDrawY = y;
    if (x < 0) {
      secondDrawX = x + mapWIDTH;
    } else if (x > mapWIDTH - 2 * size) {
      secondDrawX = x - mapWIDTH;
    }
    if (y < 0) {
      secondDrawY = y + mapHEIGHT;
    } else if (y > mapHEIGHT - 2 * size) {
      secondDrawY = y - mapHEIGHT;
    }
    shape.setPosition(secondDrawX*zoom+mapX, secondDrawY*zoom+mapY);
    window.draw(shape);
  }
  shape.setPosition(x*zoom+mapX, y*zoom+mapY);
  window.draw(shape);
}