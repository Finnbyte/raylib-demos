#include <raylib.h>

#ifndef __BOUNCING_DVD_H__
#define __BOUNCING_DVD_H__

typedef struct {
    int x;
    int y;
} Pos;

typedef struct {
    Pos pos;
    Texture2D texture;
    int width;
    int height;
    int velocity_x;
    int velocity_y;
} DVD;

void UpdateDVD(DVD* dvd, void (*on_collision)(void));

void DrawDVD(DVD dvd);

void DrawBounceCounter(int x, int y, int font_size, int bounces);

#endif // !__BOUNCING_DVD_H__
