#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include "dvd.h"

#define DVD_WIDTH 200
#define DVD_HEIGHT 100

Texture2D load_dvd_texture(const char* color) {
    char* file_path = malloc(sizeof(char) * 20);
    sprintf(file_path, "resources/dvds/%s.png", color);

    Image dvd_logo_img = LoadImage(file_path);
    ImageResize(&dvd_logo_img, DVD_WIDTH, DVD_HEIGHT);

    Texture2D dvd_logo_texture = LoadTextureFromImage(dvd_logo_img);

    UnloadImage(dvd_logo_img);
    free(file_path);

    return dvd_logo_texture;
}

