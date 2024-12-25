#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "player.h"
#include <cstdlib>
#include <raylib.h>
#include <vector>

// circle struct
struct Circle {
  Vector2 center;
  float radius;
  Color color;
  int health;
};
// Uodates the position of the circle
void UpdateCircle(Circle *circle, float speed, int screen_height);

void DrawRandCircle(std::vector<Circle> &circles, float speed,
                    int screen_height);

bool checkCollissionCirclePlayer(const Circle &circle, const Rectangle &player);
#endif /* OBSTACLE_H */
