#include "framebuffer.h"

void draw_cursor(int x, int y)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            fb_put_pixel(x + i, y + j, 0xFFFFFF);
}
