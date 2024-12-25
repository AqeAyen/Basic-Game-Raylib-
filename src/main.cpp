#include "../include/bullets.h"
#include "../include/game.h"
#include "../include/obstacle.h"
#include "../include/player.h"
#include "raylib.h"
#include <ctime>

int main(int argc, char **argv) {
  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGHT = 400;
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Plane");

  const int MAX_CIRCLES = 10;
  const int MIN_RADIUS = 10;
  const int MAX_RADIUS = 30; // Set the max radius limit
  bool gameOver = false;

  std::vector<Circle> circles(MAX_CIRCLES);
  Rectangle plane = {(float)SCREEN_WIDTH / 2 - 12.5f, (float)SCREEN_HEIGHT / 2,
                     25, 50};
  std::vector<bullet> bullets;
  int playerScore;

  ResetGame(plane, circles, bullets, SCREEN_WIDTH, SCREEN_HEIGHT, MIN_RADIUS,
            MAX_RADIUS, playerScore);

  float planeSpeed = 400.0f;

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (gameOver) {
      if (IsKeyPressed(KEY_ENTER)) { // Restart the game
        gameOver = false;
        ResetGame(plane, circles, bullets, SCREEN_WIDTH, SCREEN_HEIGHT,
                  MIN_RADIUS, MAX_RADIUS, playerScore);
      }
    } else {
      // Player movement
      MovePlayer(&plane, planeSpeed);

      // Boundary checking
      CheckBoundary(&plane, SCREEN_WIDTH, SCREEN_HEIGHT);

      // Shoot bullets
      if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        bullets.push_back({{plane.x + plane.width / 2, plane.y}, 300.0f});
      }
      UpdateBullets(bullets, SCREEN_HEIGHT);

      CheckBulletCircleCollission(bullets, circles, playerScore);

      // Check for collision
      for (const Circle &circle : circles) {
        if (checkCollissionCirclePlayer(circle, plane)) {
          gameOver = true;
          break;
        }
      }
    }

    // Drawing
    BeginDrawing();
    ClearBackground(BLACK);
    if (!gameOver) {
      DrawText(TextFormat("Score: %d", playerScore), 0, 0, 12, WHITE);
    }
    if (gameOver) {
      DrawText("Game Over!", SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 10, 20,
               RED);
      DrawText("Press 'Enter' to Restart", SCREEN_WIDTH / 2 - 70,
               SCREEN_HEIGHT / 2 + 20, 20, WHITE);
      DrawText(TextFormat("Score: %d", playerScore), SCREEN_WIDTH / 2,
               SCREEN_HEIGHT / 2 - 30, 12, WHITE);
    } else {
      DrawBullets(bullets);
      DrawRectangleRec(plane, WHITE);
      DrawRandCircle(circles, 100, SCREEN_HEIGHT);
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
