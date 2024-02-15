#include <raylib.h>

#ifndef __BOUNCING_DVD_H__
#define __BOUNCING_DVD_H__

typedef struct {
    int x;
    int y;
} Pos;

void UpdateDVD(Pos *pos, int *dvd_x_velocity, int *dvd_y_velocity, void (*on_collision)(void)) ;
    Texture2D texture;

void DrawDVD(Pos pos);

void DrawBounceCounter(int x, int y, int font_size, int bounces);


#endif // !__BOUNCING_DVD_H__
