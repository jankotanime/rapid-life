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
