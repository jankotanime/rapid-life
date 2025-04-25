#include "App.hpp"
#include <iostream>
#include <math.h>

void App::processEvents() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) close();
    if (event.type == sf::Event::KeyPressed) {
      if (menu) {
        switch (event.key.code) {
          case sf::Keyboard::Space: initial = true; break;
          default:
            break;
        }
      }
      if (start) {
        switch (event.key.code) {
          case sf::Keyboard::Space:
          std::cout<< "space" << std::endl;       
          break;
          case sf::Keyboard::F:
          find = &pigs.front(); 
          break;
          case sf::Keyboard::Left: x+=5/zoom; break;
          case sf::Keyboard::Right: x-= 5/zoom; break;
          case sf::Keyboard::Up: y+=5/zoom; break;
          case sf::Keyboard::Down: y-=5/zoom; break;
          case sf::Keyboard::PageUp: if (zoom < 2) {
            zoom+=0.1;
            x-=round(0.05*WIDTH-x*0.1);
            y-=round(0.05*HEIGHT-y*0.1);
          } break;
          case sf::Keyboard::PageDown: if (zoom > 0.3) {
            zoom-=0.1;
            x+=round(0.05*WIDTH-x*0.1);
            y+=round(0.05*HEIGHT-y*0.1);
          } break;
          case sf::Keyboard::Backspace: debug = !debug; break;
          default:
          break;
        }
      }
    }
  }
}