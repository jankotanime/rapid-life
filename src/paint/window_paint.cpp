#include "App.hpp"

void context_paint(sf::RenderWindow& window, int w, int h) {
  sf::RectangleShape border({w*1.f, h*1.f});
  border.setFillColor(sf::Color(20, 20, 20));
  border.setPosition(0, 0);
  window.draw(border);
}

void menu_paint(sf::RenderWindow& window, int w, int h) {
  sf::RectangleShape field({(w-40)*1.f, (h-40)*1.f});
  field.setFillColor(sf::Color(200, 200, 200));
  field.setPosition(20, 20);
  window.draw(field);
}

void paintFindObject(sf::RenderWindow& window, std::shared_ptr<Object> object, int mapX, int mapY, int mapWIDTH, int mapHEIGHT, double zoom) {
  sf::CircleShape shape;
  shape.setFillColor(sf::Color(250, 0, 250));
  shape.setRadius(object->getSize()*1.f);
  shape.setScale({zoom*1.f, zoom*1.f});
  bool secondDraw = (object->getX() < 0 || object->getX() > mapWIDTH - 2 * object->getSize() || object->getY() < 0 || object->getY() > mapHEIGHT - 2 * object->getSize());
  if (secondDraw) {
    int secondDrawX = object->getX();
    int secondDrawY = object->getY();
    if (object->getX() < 0) {
      secondDrawX = object->getX() + mapWIDTH;
    } else if (object->getX() > mapWIDTH - 2 * object->getSize()) {
      secondDrawX = object->getX() - mapWIDTH;
    }
    if (object->getY() < 0) {
      secondDrawY = object->getY() + mapHEIGHT;
    } else if (object->getY() > mapHEIGHT - 2 * object->getSize()) {
      secondDrawY = object->getY() - mapHEIGHT;
    }
    shape.setPosition(secondDrawX * zoom + mapX, secondDrawY * zoom + mapY);
    window.draw(shape);
  }
  shape.setPosition(object->getX() * zoom + mapX, object->getY() * zoom + mapY);
  window.draw(shape);
}

void paintObjectStats(sf::RenderWindow& window, std::shared_ptr<Object> object) {
  sf::RectangleShape container({(200)*1.f, (600)*1.f});
  container.setFillColor(sf::Color(60, 60, 60));
  container.setPosition(0, 0);
  window.draw(container);
  sf::Font font;
  if (!font.loadFromFile("src/SparkyStonesRegular-BW6ld.ttf")) {
    std::cout << "Error: Problem z czcionką!" << std::endl;
    return;
  }
  sf::Text text;
  text.setFont(font);
  text.setFillColor(sf::Color::White);
  text.setCharacterSize(10);
  text.setPosition(10, 10);
  text.setString("id: " + object->getId());
  window.draw(text);
  text.setCharacterSize(16);
  text.setPosition(10, 30);
  text.setString("x: " + std::to_string(object->getX()));
  window.draw(text);
  text.setPosition(10, 50);
  text.setString("y: " + std::to_string(object->getY()));
  window.draw(text);
  text.setPosition(10, 70);
  text.setString("size: " + std::to_string(object->getSize()));
  window.draw(text);
  text.setPosition(10, 90);
  text.setString("age: " + std::to_string(object->getAge()));
  window.draw(text);
  text.setPosition(10, 110);
  std::string species;
  switch (object->getSpecies()) {
    case Bears:    species = "Bear"; break;
    case Carrots:  species = "Carrot"; break;
    case Pigs:     species = "Pig"; break;
    case Rabbits:  species = "Rabbit"; break;
    case Shrooms:  species = "Shroom"; break;
    case Foxes:    species = "Fox"; break;
    case Lynxes:   species = "Lynx"; break;
    case Berries:  species = "Berry"; break;
    case Beavers:  species = "Beaver"; break;
    default:       species = "Corpses"; break;
  }
  text.setString("Species: " + species);
  window.draw(text);


  text.setPosition(10, 140);
  text.setString("Bloodline: ");
  window.draw(text);

  int i = 0;
  for (std::string blood : object->getBloodline()) {
    text.setPosition(10, 160 + 20*i);
    text.setString(blood);
    window.draw(text);
    i++;
  }
}
