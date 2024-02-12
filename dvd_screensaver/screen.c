#include <raylib.h>
#include "screen.h"
#include <stddef.h>
#include <stdio.h>

#define DVD_SIZE 100
#define DVD_FONT_SIZE 20
#define BOUNCE_COUNTER_TOP_GAP 10

void UpdateDVD(Pos *pos, int *dvd_x_velocity, int *dvd_y_velocity, void (*on_collision)(void)) {
    pos->x += *dvd_x_velocity;
    pos->y += *dvd_y_velocity;

    if (pos->x <= 0 || pos->x >= (GetScreenWidth() - DVD_SIZE)) {
        *dvd_x_velocity = -(*dvd_x_velocity);
        if (on_collision != NULL) {
            on_collision();
        }
    } 

    if (pos->y <= 0 || pos->y >= (GetScreenHeight() - DVD_SIZE)) {
        *dvd_y_velocity = -(*dvd_y_velocity);
        if (on_collision != NULL) {
            on_collision();
        }
    }
}

void DrawDVD(Pos pos) {
    DrawRectangle(pos.x, pos.y, DVD_SIZE, DVD_SIZE, PURPLE);
    DrawText("DVD", (pos.x + (DVD_SIZE / 2) - DVD_FONT_SIZE), 
        (pos.y + (DVD_SIZE / 2) - (DVD_FONT_SIZE / 2)), DVD_FONT_SIZE, WHITE);
}

void DrawBounceCounter(int x, int y, int font_size, int bounces) {
    char str[sizeof(char) * 12];
    sprintf(str, "Bounces: %d", bounces);
    DrawText(str, x + BOUNCE_COUNTER_TOP_GAP, y + BOUNCE_COUNTER_TOP_GAP, font_size, WHITE);
}
