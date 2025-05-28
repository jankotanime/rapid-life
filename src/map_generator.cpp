#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Map.hpp"
#include "math.h"

#define DEG2RAD(angle) ((angle) * M_PI / 180.0)

// TODO: Fix protruding shapes

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
    const int minLength = 70;
    const int maxLength = 80;
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
    
    pond.setFillColor(sf::Color(60, 60, 140));
    pond.setPointCount(points_new.size());
    for (std::size_t i = 0; i < points_new.size(); ++i) {
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
      const int minLength = 50;
      const int maxLength = 60;
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
      for (std::size_t i = 0; i < points_new.size(); ++i) {
        forest.setPoint(i, points_new[i]);
      }
      chunks.push_front({forest, Forest});
    }  

  // Savanna
  int savannaCount = 2 + std::rand() % 4;
  for (int i = 0; i < savannaCount; i++) {
    sf::ConvexShape savanna;
    std::vector<sf::Vector2f> points_new;
    int startX = std::rand() % x;
    int startY = std::rand() % y;
    points_new.push_back({static_cast<float>(startX), static_cast<float>(startY)});

    const int numPoints = 8 + std::rand() % 8;
    const int minLength = 140;
    const int maxLength = 150;
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

    savanna.setFillColor(sf::Color(230, 210, 120));
    savanna.setPointCount(points_new.size());
    for (std::size_t i = 0; i < points_new.size(); ++i) {
      savanna.setPoint(i, points_new[i]);
    }
    chunks.push_front({savanna, Savanna});
  }

  // Plains
  sf::ConvexShape convex;
  std::vector<sf::Vector2f> points;
  points.push_back({static_cast<float>(0), static_cast<float>(0)});
  points.push_back({static_cast<float>(x), static_cast<float>(0)});
  points.push_back({static_cast<float>(x), static_cast<float>(y)});
  points.push_back({static_cast<float>(0), static_cast<float>(y)});
  convex.setFillColor(sf::Color(100, 155, 50));
  convex.setPointCount(points.size());
  for (int i = 0; i < 4; i++) {
    convex.setPoint(i, points[i]);
  }
  chunks.push_front({convex, Grass});
}