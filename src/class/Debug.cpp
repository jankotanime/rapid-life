#include <SFML/Graphics.hpp>
#include <iostream>
#include "Debug.hpp"
#include "Map.hpp"

Debug::Debug(int w, int h, int mW, int mH) : WIDTH(w), HEIGHT(h), mapWIDTH(mW), mapHEIGHT(mH) {}

void Debug::show() {
  shown = !shown;
}

bool Debug::getShown() {
  return shown;
}

void Debug::paintMouseCords(sf::RenderWindow& window, Map map, int mapX, int mapY, double zoom, float fps) {
  sf::Font font;
  if (!font.loadFromFile("src/SparkyStonesRegular-BW6ld.ttf")) {
    std::cout << "Error: Problem z czcionką!" << std::endl;
    return;
  }
  sf::Vector2i position = sf::Mouse::getPosition(window);
  sf::Text text;
  text.setFont(font);
  text.setFillColor(sf::Color::White);
  text.setCharacterSize(12);
  text.setPosition(WIDTH-100, 10);

  if ((position.x-mapX)/zoom < 0) {
    text.setString("x: " + std::to_string(0));
  } else if ((position.x-mapX)/zoom > mapWIDTH) {
    text.setString("x: " + std::to_string(2000));
  } else {
    text.setString("x: " + std::to_string(static_cast<int>((position.x-mapX)/zoom)));
  }
  window.draw(text);
    
  text.setPosition(WIDTH-50, 10);
  if ((position.y-mapY)/zoom < 0) {
    text.setString("y: " + std::to_string(0));
  } else if ((position.y-mapY)/zoom > mapHEIGHT) {
    text.setString("y: " + std::to_string(2000));
  } else {
    text.setString("y: " + std::to_string(static_cast<int>((position.y-mapY)/zoom)));
  }
  window.draw(text);

  sf::Vector2f position2f({static_cast<float>((position.x-mapX)/zoom), static_cast<float>((position.y-mapY)/zoom)});

  Biome biome = map.getCordsChunk(position2f);

  text.setPosition(WIDTH-100, 20);
  switch (biome) {
    case 0: text.setString("Biome: Plains"); break;
    case 1: text.setString("Biome: Pond"); break;
    case 2: text.setString("Biome: Forest"); break;
    case 3: text.setString("Biome: Savanna"); break;
    default: return;
  }
  window.draw(text);
  text.setPosition(WIDTH-100, 35);
  text.setString("FPS: " + std::to_string(static_cast<int>(fps)));
  window.draw(text);
}