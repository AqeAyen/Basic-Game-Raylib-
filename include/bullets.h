#ifndef BULLETS_H
#define BULLETS_H

#include "obstacle.h"
#include "player.h"
#include <vector>
struct bullet {
  Vector2 position;
  float speed;
};

void UpdateBullets(std::vector<bullet> &Bullets, int screen_height);

void DrawBullets(const std::vector<bullet> &bullets);

void CheckBulletCircleCollission(std::vector<bullet> &bullets,
                                 std::vector<Circle> &circles,
                                 int &playerScore);
#endif /* BULLETS_H */
