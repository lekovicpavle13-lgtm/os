#include "framebuffer.h"

uint32_t* framebuffer;
uint32_t width;
uint32_t height;

void fb_init(uint32_t* fb, uint32_t w, uint32_t h)
{
    framebuffer = fb;
    width = w;
    height = h;
}

void fb_put_pixel(int x, int y, uint32_t color)
{
    framebuffer[y * width + x] = color;
}

void fb_clear(uint32_t color)
{
    for (uint32_t y = 0; y < height; y++)
        for (uint32_t x = 0; x < width; x++)
            fb_put_pixel(x, y, color);
}

