#ifndef GAME_H
#define GAME_H
#include "bullets.h"
#include "obstacle.h"
#include "player.h"
#include <vector>
void ResetGame(Rectangle &plane, std::vector<Circle> &circles,
               std::vector<bullet> &bullets, int screen_width,
               int screen_height, int min_radius, int max_radius,
               int &playerScore);
#endif /* GAME_H */
