#pragma once
#include <stdint.h>

extern uint32_t* framebuffer;
extern uint32_t width;
extern uint32_t height;

void fb_init(uint32_t* fb, uint32_t w, uint32_t h);
void fb_put_pixel(int x, int y, uint32_t color);
void fb_clear(uint32_t color);

