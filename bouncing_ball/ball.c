#include <raylib.h>
#include "ball.h"

#define ACCELERATION 2 

void UpdateBall(Ball *ball) {
    const bool should_bounce = ball->y >= (GetScreenHeight() - ball->radius) && ball->velocity > 0;
    const bool should_be_stationary = ball->y >= (GetScreenHeight() - ball->radius) && ball->velocity == 0;
    if (should_be_stationary) {
        return;
    }

    ball->velocity += ACCELERATION;
    ball->y += ball->velocity;

    if (should_bounce) {
        ball->velocity = -(ball->velocity);
    }
}


void DrawBall(Ball *ball) {
    DrawCircle(GetScreenWidth()/2, ball->y, ball->radius, WHITE);
}
