#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animal.hpp"
#include "Fruit.hpp"
#include <cstdlib>
#include <math.h>
#define PI 3.141592654

bool includeInForwardList(std::forward_list<Species> list, Species elem) {
  for (Species& e : list) {
    if (e == elem) {
      return true;
    }
  }
  return false;
}

Animal::Animal(int x, int y, int s, int v) : Object(x, y, s) {
  vision = v;
  visionShape.setRadius(vision*1.f);
  visionShape.setFillColor(sf::Color(100, 100, 100, 50));
  int r = rand() % 360;
  this->direction = r;
}

Species Animal::getSpecies() {
  return species;
}

void Animal::findDirection(int mapWidth, int mapHeight) {
  int closestDistance = vision;
  for (auto& repulser : repulsers) {
    int distance = sqrt(pow((repulser->getX() - x) % mapWidth, 2) + pow((repulser->getY() - y) % mapHeight, 2));
    if (distance < closestDistance) {
      closestDistance = distance;
      direction = atan2(y - repulser->getY(), x - repulser->getX()) * (180.0 / PI);
    }
  }
  if (closestDistance != vision) return;
  for (auto& attractor : attractors) {
    int distance = sqrt(pow((attractor->getX() - x) % mapWidth, 2) + pow((attractor->getY() - y) % mapHeight, 2));
    if (distance < size/2) {
      attractor->kill();
    }
    else if (distance < closestDistance) {
      closestDistance = distance;
      direction = atan2(attractor->getY() - y, attractor->getX() - x) * (180.0 / PI);
    }
  }
  if (closestDistance != vision) return;
  int r = rand() % 21;
  direction += r - 10;
}

void Animal::move(float delta) {
  direction = fmod(direction + 360, 360);
  x += 0.5*round(delta*speed*cos((direction*PI)/180));
  y += 0.5*round(delta*speed*sin((direction*PI)/180));
}

void Animal::drawVision(sf::RenderWindow& window, int mapX, int mapY, int mapWIDTH, int mapHEIGHT, double zoom) {
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

void Animal::chooseDetractor(std::forward_list<Animal>& animals, std::forward_list<Fruit>& fruits) {
  attractors = std::forward_list<std::shared_ptr<Object>>();
  repulsers = std::forward_list<std::shared_ptr<Object>>();
  for (Animal& animal : animals) {
    if (includeInForwardList(attractorSpecies, animal.getSpecies())) {
      attractors.push_front(std::shared_ptr<Object>(&animal, [](Object*){}));
    }
  }
  for (Fruit& fruit : fruits) {
    if (includeInForwardList(attractorSpecies, fruit.getSpecies())) {
      attractors.push_front(std::shared_ptr<Object>(&fruit, [](Object*){}));
    }
  }
}
