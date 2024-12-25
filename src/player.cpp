#include "../include/player.h"

void MovePlayer(Rectangle *player, float playerSpeed) {
  if (IsKeyDown(KEY_RIGHT)) {
    player->x += playerSpeed * GetFrameTime();
  }
  if (IsKeyDown(KEY_LEFT)) {
    player->x -= playerSpeed * GetFrameTime();
  }
  if (IsKeyDown(KEY_UP)) {
    player->y -= playerSpeed * GetFrameTime();
  }
  if (IsKeyDown(KEY_DOWN)) {
    player->y += playerSpeed * GetFrameTime();
  }
}

void CheckBoundary(Rectangle *player, int SCREEN_WIDTH, int SCREEN_HEIGHT) {
  if (player->x > SCREEN_WIDTH) {
    player->x = 0;
  }
  if (player->x + player->width < 0) {
    player->x = SCREEN_WIDTH - player->width;
  }
  if (player->y < 0) {
    player->y = 0;
  }
  if (player->y + player->height > SCREEN_HEIGHT) {
    player->y = SCREEN_HEIGHT - player->height;
  }
}
