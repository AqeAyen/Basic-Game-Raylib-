#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
void MovePlayer(Rectangle *player, float playerSpeed);

void CheckBoundary(Rectangle *player, int SCREEN_WIDTH, int SCREEN_HEIGHT);
#endif /* PLAYER_H */
