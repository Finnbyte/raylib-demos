#include <raylib.h>
#include "screen.h"
#include <stddef.h>
#include <stdio.h>

#define DVD_SIZE 100
#define DVD_FONT_SIZE 20
#define BOUNCE_COUNTER_TOP_GAP 10

void UpdateDVD(DVD* dvd, void (*on_collision)(void)) {
    dvd->pos.x += dvd->velocity_x;
    dvd->pos.y += dvd->velocity_y;

    if (dvd->pos.x <= 0 || dvd->pos.x >= (GetScreenWidth() - dvd->texture.width)) {
        dvd->velocity_x = -(dvd->velocity_x);
        if (on_collision != NULL) {
            on_collision();
        }
    } 

    if (dvd->pos.y <= 0 || dvd->pos.y >= (GetScreenHeight() - dvd->texture.height)) {
        dvd->velocity_y = -(dvd->velocity_y);
        if (on_collision != NULL) {
            on_collision();
        }
    }
}

void DrawDVD(DVD dvd) {
    DrawTexture(dvd.texture, dvd.pos.x, dvd.pos.y, WHITE);
}

void DrawBounceCounter(int x, int y, int font_size, int bounces) {
    char str[sizeof(char) * 16];
    sprintf(str, "Bounces: %d", bounces);
    DrawText(str, x + BOUNCE_COUNTER_TOP_GAP, y + BOUNCE_COUNTER_TOP_GAP, font_size, GRAY);
}
