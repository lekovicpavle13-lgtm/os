#include "../drivers/framebuffer.h"
#include "mouse.h"
#include "gui.h"
#define MAX_WINDOWS 10

window_t* windows[MAX_WINDOWS];
int window_count = 0;

int focused = -1;

void gui_add_window(window_t* w)
{
    if (window_count < MAX_WINDOWS)
        windows[window_count++] = w;
}

static void draw_window(window_t* w)
{
    for (int y = 0; y < w->h; y++)
        for (int x = 0; x < w->w; x++)
            fb_put_pixel(w->x + x, w->y + y, w->color);

    // title bar
    for (int y = 0; y < 20; y++)
        for (int x = 0; x < w->w; x++)
            fb_put_pixel(w->x + x, w->y + y, 0x222222);
}

void gui_update()
{
    focused = -1;

    for (int i = 0; i < window_count; i++)
    {
        window_t* w = windows[i];

        // click detection
        if (mouse_x > w->x && mouse_x < w->x + w->w &&
            mouse_y > w->y && mouse_y < w->y + 20)
        {
            w->dragging = 1;
            focused = i;
        }

        if (w->dragging)
        {
            w->x = mouse_x - 50;
            w->y = mouse_y - 10;
        }

        draw_window(w);
    }
}
