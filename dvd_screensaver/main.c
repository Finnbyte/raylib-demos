#include <stddef.h>
#include <raylib.h>
#include "screen.h"
#include "dvd.h"
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define INITIAL_DVD_X 100
#define INITIAL_DVD_Y 100
#define INITIAL_DVD_TEXTURE_INDEX 1 // blue
#define DVD_VELOCITY 2
#define DVD_COLORS_LENGTH 8

const char* dvd_colors[DVD_COLORS_LENGTH] = { "green", "blue", "magenta", "orange", "red", "yellow", "purple", "cyan" };

static void InitDVD(void);
static void InitDVDTextures(void);
static void UpdateDrawFrame(void);
static void UnloadResources();
static void on_dvd_collision(void);

static DVD dvd = {0};
static Texture2D dvd_textures[DVD_COLORS_LENGTH] = {0};
static size_t current_dvd_texture_index = 0;
static int bounces = 0;
static Sound collision_sound;

static void on_dvd_collision(void) {
    bounces += 1;
    PlaySound(collision_sound);

    size_t new_texture_index;
    // Iterate until we get a unique index
    while ((new_texture_index = rand() % DVD_COLORS_LENGTH) == current_dvd_texture_index) {}
    dvd.texture = dvd_textures[new_texture_index];
    current_dvd_texture_index = new_texture_index;
}

int main() {
    InitAudioDevice();
    collision_sound = LoadSound("./resources/boing.wav");

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib-physics: DVD Screensaver");
    // DVD position doesn't update without this flag set while window is minimized
    SetConfigFlags(FLAG_WINDOW_ALWAYS_RUN);

    InitDVDTextures();
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
static void InitDVDTextures(void) {
    for (size_t i = 0; i < DVD_COLORS_LENGTH; i++) {
        dvd_textures[i] = load_dvd_texture(dvd_colors[i]);
    }
}

static void InitDVD(void) {
    dvd.texture = dvd_textures[INITIAL_DVD_TEXTURE_INDEX];
    current_dvd_texture_index = INITIAL_DVD_TEXTURE_INDEX;
    dvd.velocity_x = DVD_VELOCITY;
    dvd.velocity_y = DVD_VELOCITY;
    dvd.pos.x = INITIAL_DVD_X;
    dvd.pos.y = INITIAL_DVD_Y;
}

static void UpdateDrawFrame(void) {
    UpdateDVD(&dvd, on_dvd_collision);
    BeginDrawing();
        ClearBackground(BLACK);
        DrawDVD(dvd);
        DrawBounceCounter(0, 0, 30, bounces);
    EndDrawing();
   
}
