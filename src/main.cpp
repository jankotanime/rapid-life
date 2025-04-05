#include <SFML/Graphics.hpp>
#include <iostream>

void context_paint(sf::RenderWindow&, int, int);
void menu_paint(sf::RenderWindow&, int, int);

int main() {
  // sf::ContextSettings settings;
  // settings.antialiasingLevel = 0;
  // settings.majorVersion = 2;
  // settings.minorVersion = 1;
  // settings.attributeFlags = sf::ContextSettings::Default;

  int WIDTH = 800;
  int HEIGHT = 600;
  int menu = true;

  sf::RenderWindow window(
    sf::VideoMode(WIDTH, HEIGHT),
    "Rapid life",
    sf::Style::Default
    // settings
  );

  if (!window.isOpen()) {
    std::cerr << "BLAD: Nie mozna utworzyc okna! Sprawdz czy X Server";
    std::cerr << "jest uruchomiony i czy zmienna DISPLAY jest ustawiona?\n";
    return 1;
  }

  window.setPosition({0, 0});

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
    }

    window.clear(sf::Color::Black);
    context_paint(window, WIDTH, HEIGHT);
    if (menu) {
      menu_paint(window, WIDTH, HEIGHT);
    }
    window.display();
  }

  return 0;
}

// export DISPLAY=$(ip route list default | awk '{print $3}'):0