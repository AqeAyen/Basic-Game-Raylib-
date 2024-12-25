#include "../include/bullets.h"

void UpdateBullets(std::vector<bullet> &Bullets, int screen_height) {
  for (size_t i = 0; i < Bullets.size();) {
    Bullets[i].position.y -= Bullets[i].speed * GetFrameTime();

    if (Bullets[i].position.y < 0) {
      Bullets.erase(Bullets.begin() + i);
    } else {
      ++i;
    }
  }
}

void DrawBullets(const std::vector<bullet> &bullets) {
  for (const bullet &bullet : bullets) {
    DrawCircleV(bullet.position, 5, YELLOW);
  }
}

void CheckBulletCircleCollission(std::vector<bullet> &bullets,
                                 std::vector<Circle> &circles,
                                 int &playerScore) {

  for (size_t i = 0; i < bullets.size();) {
    bool bulletRemoved = false;

    for (size_t j = 0; j < circles.size(); ++j) {
      if (CheckCollisionCircleRec(
              circles[j].center, circles[j].radius,
              {bullets[i].position.x - 5, bullets[i].position.y - 5, 10, 10})) {
        circles[j].health -= 10;            // Reduce health
        bullets.erase(bullets.begin() + i); // Remove bullet
        bulletRemoved = true;

        if (circles[j].health <= 0) {
          circles.erase(circles.begin() + j); // Remove circle
          ++playerScore;
        }
        break;
      }
    }

    if (!bulletRemoved) {
      ++i;
    }
  }
}
