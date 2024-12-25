#include "../include/obstacle.h"
#include <raylib.h>

void UpdateCircle(Circle *circle, float speed, int screen_height) {
  circle->center.y += speed * GetFrameTime();

  if (circle->center.y - circle->radius > screen_height) {
    circle->center.y = -circle->radius;
    circle->center.x = rand() % GetScreenWidth();
  }
}

void DrawRandCircle(std::vector<Circle> &circles, float speed,
                    int screen_height) {
  for (Circle &circle : circles) {
    UpdateCircle(&circle, speed, screen_height);

    // Update radius to match health
    circle.radius = circle.health > 0 ? static_cast<float>(circle.health) : 0;

    DrawCircleV(circle.center, circle.radius, circle.color);
  }
}

bool checkCollissionCirclePlayer(const Circle &circle,
                                 const Rectangle &player) {
  return CheckCollisionCircleRec(circle.center, circle.radius, player);
}
