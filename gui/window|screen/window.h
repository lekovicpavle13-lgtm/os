#pragma once
#include <stdint.h>

typedef struct {
    int x, y, w, h;
    uint32_t color;
    int dragging;
} window_t;

