#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Map.hpp"
#include "math.h"

#define DEG2RAD(angle) ((angle) * M_PI / 180.0)

Map::Map(int x, int y) : borderX(x), borderY(y) {
  // Ponds
  int pondsCount = 5 + std::rand() % 6;
  for (int i = 0; i < pondsCount; i++) {
    sf::ConvexShape pond;
    std::vector<sf::Vector2f> points_new;
    int startX = std::rand() % x;
    int startY = std::rand() % y;
    points_new.push_back({static_cast<float>(startX), static_cast<float>(startY)});

    const int numPoints = 10 + std::rand() % 5;
    const int minLength = 55;
    const int maxLength = 65;
    const int minAngle = floor(360/numPoints) - 6;
    const int maxAngle = floor(360/numPoints) + 6;
    double currentAngle = 0.0;
    int newX = startX, newY = startY;

    for (int i = 0; i < numPoints; ++i) {
      int length = minLength + (std::rand() % (maxLength - minLength));
      int angleStep = minAngle + (std::rand() % (maxAngle - minAngle));
      currentAngle += angleStep;
      double rad = DEG2RAD(currentAngle);
      newX += length * cos(rad);
      newY += length * sin(rad);
      if (newX > x) { newX = x; }
      if (newX < 0) { newX = 0; }
      if (newY > y) { newY = y; }
      if (newY < 0) { newY = 0; }
      points_new.push_back({static_cast<float>(newX), static_cast<float>(newY)});
    }

    pond.setFillColor(sf::Color(20, 20, 140));
    pond.setPointCount(points_new.size());
    for (int i = 0; i < points_new.size(); i++) {
      pond.setPoint(i, points_new[i]);
    }
    chunks.push_front({pond, Water});
  }

  // Forests
  int forestsCount = 10 + std::rand() % 6;
  for (int i = 0; i < forestsCount; i++) {
    sf::ConvexShape forest;
    std::vector<sf::Vector2f> points_new;
    int startX = std::rand() % x;
    int startY = std::rand() % y;
    points_new.push_back({static_cast<float>(startX), static_cast<float>(startY)});

    const int numPoints = 8 + std::rand() % 8;
    const int minLength = 40;
    const int maxLength = 50;
    const int minAngle = floor(360/numPoints) - 6;
    const int maxAngle = floor(360/numPoints) + 6;
    double currentAngle = 0.0;
    int newX = startX, newY = startY;

    for (int i = 0; i < numPoints; ++i) {
      int length = minLength + (std::rand() % (maxLength - minLength));
      int angleStep = minAngle + (std::rand() % (maxAngle - minAngle));
      currentAngle += angleStep;
      double rad = DEG2RAD(currentAngle);
      newX += length * cos(rad);
      newY += length * sin(rad);
      if (newX > x) { newX = x; }
      if (newX < 0) { newX = 0; }
      if (newY > y) { newY = y; }
      if (newY < 0) { newY = 0; }
      points_new.push_back({static_cast<float>(newX), static_cast<float>(newY)});
    }

    forest.setFillColor(sf::Color(20, 70, 30));
    forest.setPointCount(points_new.size());
    for (int i = 0; i < points_new.size(); i++) {
      forest.setPoint(i, points_new[i]);
    }
    chunks.push_front({forest, Forest});
  }

  // Plains
  sf::ConvexShape convex;
  std::vector<sf::Vector2f> points;
  points.push_back({static_cast<float>(0), static_cast<float>(0)});
  points.push_back({static_cast<float>(x), static_cast<float>(0)});
  points.push_back({static_cast<float>(x), static_cast<float>(y)});
  points.push_back({static_cast<float>(0), static_cast<float>(y)});
  convex.setFillColor(sf::Color(80, 200, 100));
  convex.setPointCount(points.size());
  for (int i = 0; i < 4; i++) {
    convex.setPoint(i, points[i]);
  }
  chunks.push_front({convex, Grass});
}