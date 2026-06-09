#include <stdint.h>
#include "kernel.h"
#include "../drivers/framebuffer.h"

void paging_init();
void idt_init();
void pic_remap();

typedef struct {
    int x, y, w, h;
    uint32_t color;
} window_t;

void draw_window(window_t* win)
{
    for (int y = 0; y < win->h; y++)
        for (int x = 0; x < win->w; x++)
            fb_put_pixel(win->x + x, win->y + y, win->color);
}

void kernel_main()
{
    fb_init((uint32_t*)0xE0000000, 1024, 768);
    fb_clear(0x000000);

    paging_init();
    idt_init();
    pic_remap();

    asm volatile("sti");

    window_t w1 = {100, 100, 300, 200, 0x2222FF};
    window_t w2 = {200, 200, 300, 200, 0x22FF22};

    draw_window(&w1);
    draw_window(&w2);

    while (1)
        asm volatile("hlt");
}
