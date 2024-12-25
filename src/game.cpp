#include "../include/game.h"

// Function to reset the game state
void ResetGame(Rectangle &plane, std::vector<Circle> &circles,
               std::vector<bullet> &bullets, int screen_width,
               int screen_height, int min_radius, int max_radius,
               int &playerScore) {
  // Reset player position
  plane = {(float)screen_width / 2 - 12.5f, (float)screen_height / 2, 25, 50};
  playerScore = 0;

  // Clear bullets
  bullets.clear();

  // Reset circles
  for (Circle &circle : circles) {
    circle.center.x = rand() % screen_width;
    circle.center.y = -(rand() % screen_height); // Spawn above the screen
    circle.radius = rand() % (max_radius - min_radius + 1) + min_radius;
    circle.color = {
        static_cast<unsigned char>(rand() % 256),
        static_cast<unsigned char>(rand() % 256),
        static_cast<unsigned char>(rand() % 256),
        255 // Fully opaque
    };
    circle.health = static_cast<int>(circle.radius); // Health tied to radius
  }
}
