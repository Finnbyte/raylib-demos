#include <raylib.h>
#include <stddef.h>
#include "screen.h"
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define INITIAL_DVD_X 200
#define INITIAL_DVD_Y 200

static void InitDVD(void);
static void UpdateDrawFrame(void);
static void UnloadResources();
static void on_dvd_collision(void);

static Pos dvd_pos = { 0 };

static int dvd_x_velocity = 0;
static int dvd_y_velocity = 0;
static int bounces = 0;
static Sound collision_sound;

static void on_dvd_collision(void) {
    bounces += 1;
    PlaySound(collision_sound);
}

int main() {
    InitAudioDevice();
    collision_sound = LoadSound("./resources/boing.wav");

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib-physics: DVD Screensaver");

    InitDVD();

    SetTargetFPS(50);

    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }

    UnloadResources();
    CloseAudioDevice();
    CloseWindow();
}

static void UnloadResources(void) {
    UnloadSound(collision_sound);
}

static void InitDVD(void) {
    dvd_x_velocity = 5;
    dvd_y_velocity = 6;
    dvd_pos.x = INITIAL_DVD_X;
    dvd_pos.y = INITIAL_DVD_Y;
}

static void UpdateDrawFrame(void) {
    UpdateDVD(&dvd_pos, &dvd_x_velocity, &dvd_y_velocity, on_dvd_collision);
    BeginDrawing();
        ClearBackground(BLACK);
        DrawDVD(dvd_pos);
        DrawBounceCounter(0, 0, 50, bounces);
    EndDrawing();
   
}
