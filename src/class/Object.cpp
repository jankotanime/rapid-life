#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.hpp"
#include "Corpse.hpp"

Object::Object(int x, int y, int s) : x(x), y(y), size(s) {
  shape.setRadius(s*1.f);
}

bool Object::aging() {
  age++;
  return rand() % (50 - age) == 0;
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