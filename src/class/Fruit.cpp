#include <SFML/Graphics.hpp>
#include <iostream>
#include "Fruit.hpp"

Fruit::Fruit(int x, int y, int s, int r) : Object(x, y, s), range(r) {
  rangeShape.setRadius(range*1.f);
  rangeShape.setFillColor(sf::Color(100, 100, 100, 50));
}

Species Fruit::getSpecies() {
  return species;
}

void Fruit::drawRange(sf::RenderWindow& window, int mapX, int mapY, int mapWIDTH, int mapHEIGHT, double zoom) {
  int actX = x+size-range;
  int actY = y+size-range;
  rangeShape.setScale({zoom*1.f, zoom*1.f});
  bool secondDraw = (actX < 0 || actX > mapWIDTH - 2 * range || actY < 0 || actY > mapHEIGHT - 2 * range);
  if (secondDraw) {
    int secondDrawX = actX;
    int secondDrawY = actY;
    if (actX < 0) {
      secondDrawX = actX + mapWIDTH;
    } else if (actX > mapWIDTH - 2 * range) {
      secondDrawX = actX - mapWIDTH;
    }
    if (actY < 0) {
      secondDrawY = actY + mapHEIGHT;
    } else if (actY > mapHEIGHT - 2 * range) {
      secondDrawY = actY - mapHEIGHT;
    }
    rangeShape.setPosition(secondDrawX*zoom+mapX, secondDrawY*zoom+mapY);
    window.draw(rangeShape);
  }
  rangeShape.setPosition(actX*zoom+mapX, actY*zoom+mapY);
  window.draw(rangeShape);
}