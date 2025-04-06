#include "App.hpp"
#include <ctime>

int main() {
  srand(static_cast<unsigned>(time(nullptr)));
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;
  App app(settings, "Rapid life");
  app.run();
  return 0;
}
