#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.hpp"

Object::Object(int x, int y, int s) : x(x), y(y), size(s) {}

void Object::draw(sf::RenderWindow& window, int mapX, int mapY, int mapWIDTH, int mapHEIGHT) {
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
    shape.setPosition(secondDrawX+mapX, secondDrawY+mapY);
    window.draw(shape);
  }
  shape.setPosition(x+mapX, y+mapY);
  window.draw(shape);
}