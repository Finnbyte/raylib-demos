#include <raylib.h>
#include "ball.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define BALL_RADIUS 50
#define INITIAL_BALL_VELOCITY 10

static void InitBall(void);
static void UpdateDrawFrame(void);

static Ball ball = { 0 };

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib-physics: Bouncing Ball");

    InitBall();

    SetTargetFPS(50);

    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }

    CloseWindow();
}

static void InitBall() {
    ball.radius = BALL_RADIUS;
    ball.y = SCREEN_HEIGHT / 2;
    ball.velocity = INITIAL_BALL_VELOCITY;
}

static void UpdateDrawFrame() {
    UpdateBall(&ball);
    BeginDrawing();
        ClearBackground(BLACK);
        DrawBall(&ball);
    EndDrawing();
}
