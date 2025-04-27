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

void paintObjectStats(sf::RenderWindow& window, std::shared_ptr<Object> object) {
  sf::RectangleShape container({(80)*1.f, (120)*1.f});
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
  text.setString("x: " + std::to_string(object->getX()));
  text.setCharacterSize(16);
  text.setFillColor(sf::Color::White);
  text.setPosition(10, 10);
  window.draw(text);
  text.setString("y: " + std::to_string(object->getY()));
  text.setPosition(10, 30);
  window.draw(text);
}
