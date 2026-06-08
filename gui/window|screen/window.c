#include "../framebuffer.h"

typedef struct {
    int x, y, w, h;
    uint32_t color;
} window_t;

void draw_window(window_t* win)
{
    for (int y = 0; y < win->h; y++)
    {
        for (int x = 0; x < win->w; x++)
        {
            fb_put_pixel(win->x + x, win->y + y, win->color);
        }
    }
}