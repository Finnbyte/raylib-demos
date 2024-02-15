#include <raylib.h>
#include <stddef.h>
#include "screen.h"
#include "dvd.h"
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define INITIAL_DVD_X 200
#define INITIAL_DVD_Y 200
#define INITIAL_DVD_TEXTURE_INDEX 1 // blue
#define DVD_COLORS_LENGTH 8

const char* dvd_colors[DVD_COLORS_LENGTH] = { "green", "blue", "magenta", "orange", "red", "yellow", "purple", "cyan" };

static void InitDVD(void);
static void UpdateDrawFrame(void);
static void UnloadResources();
static void on_dvd_collision(void);

static Pos dvd_pos = { 0 };

static int dvd_x_velocity = 0;
static int dvd_y_velocity = 0;
static Texture2D dvd_textures[DVD_COLORS_LENGTH] = {0};
static size_t current_dvd_texture_index = 0;
static int bounces = 0;

static void on_dvd_collision(void) {
    bounces += 1;

    size_t new_texture_index;
    // Iterate until we get a unique index
    while ((new_texture_index = rand() % DVD_COLORS_LENGTH) == current_dvd_texture_index) {}
    dvd.texture = dvd_textures[new_texture_index];
    current_dvd_texture_index = new_texture_index;
}

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib-physics: DVD Screensaver");

    InitDVD();

    SetTargetFPS(50);

    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }

    UnloadResources();
    CloseWindow();
}

static void UnloadResources(void) {
static void InitDVDTextures(void) {
    for (size_t i = 0; i < DVD_COLORS_LENGTH; i++) {
        dvd_textures[i] = load_dvd_texture(dvd_colors[i]);
    }
}

static void InitDVD(void) {
    dvd_x_velocity = 5;
    dvd_y_velocity = 6;
    dvd_pos.x = INITIAL_DVD_X;
    dvd_pos.y = INITIAL_DVD_Y;
    dvd.texture = dvd_textures[INITIAL_DVD_TEXTURE_INDEX];
    current_dvd_texture_index = INITIAL_DVD_TEXTURE_INDEX;
}

static void UpdateDrawFrame(void) {
    UpdateDVD(&dvd_pos, &dvd_x_velocity, &dvd_y_velocity, on_dvd_collision);
    BeginDrawing();
        ClearBackground(BLACK);
        DrawDVD(dvd_pos);
        DrawBounceCounter(0, 0, 50, bounces);
    EndDrawing();
   
}
