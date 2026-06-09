#include "../drivers/framebuffer.h"
#include "mouse.h"
#include "window.h"
#include <stdint.h>

window_t win = {200, 150, 300, 200, 0x4444FF, 0};

void draw_window(window_t* w)
{
    for (int y = 0; y < w->h; y++)
    {
        for (int x = 0; x < w->w; x++)
        {
            fb_put_pixel(w->x + x, w->y + y, w->color);
        }
    }

    // title bar
    for (int y = 0; y < 20; y++)
        for (int x = 0; x < w->w; x++)
            fb_put_pixel(w->x + x, w->y + y, 0x222222);
}