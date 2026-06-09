#pragma once
#include <stdint.h>

typedef struct window {
    int x, y, w, h;
    int dragging;
    uint32_t color;
} window_t;

void gui_init();
void gui_update();
void gui_add_window(window_t* w);

