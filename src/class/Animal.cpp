#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animal.hpp"
#include <cstdlib>
#include <math.h>
#define PI 3.141592654

Animal::Animal(int x, int y, int s, int v) : Object(x, y, s) {
  vision = v;
  visionShape.setRadius(vision*1.f);
  visionShape.setFillColor(sf::Color(100, 100, 100, 50));
  int r = rand() % 360;
  this->direction = r;
}

void Animal::move(float delta) {
  int r = rand() % 21;
  change_direction(r);
  x += 0.5*round(delta*speed*cos((direction*PI)/180));
  y += 0.5*round(delta*speed*sin((direction*PI)/180));
}

void Animal::change_direction(int r) {
  direction += r - 10;
}

void Animal::draw_vision(sf::RenderWindow& window, int mapX, int mapY, int mapWIDTH, int mapHEIGHT, double zoom) {
  int actX = x+size-vision;
  int actY = y+size-vision;
  visionShape.setScale({zoom*1.f, zoom*1.f});
  bool secondDraw = (actX < 0 || actX > mapWIDTH - 2*vision || actY < 0 || actY > mapHEIGHT - 2 * vision);
  if (secondDraw) {
    int secondDrawX = actX;
    int secondDrawY = actY;
    if (actX < 0) {
      secondDrawX = actX + mapWIDTH;
    } else if (actX > mapWIDTH - 2 * vision) {
      secondDrawX = actX - mapWIDTH;
    }
    if (actY < 0) {
      secondDrawY = actY + mapHEIGHT;
    } else if (actY > mapHEIGHT - 2 * vision) {
      secondDrawY = actY - mapHEIGHT;
    }
    visionShape.setPosition(secondDrawX*zoom+mapX, secondDrawY*zoom+mapY);
    window.draw(visionShape);
  }
  visionShape.setPosition(actX*zoom+mapX, actY*zoom+mapY);
  window.draw(visionShape);
}
