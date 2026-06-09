
#include <stdint.h>

volatile uint16_t* vga = (uint16_t*)0xB8000;
int cursor = 0;

void print_char(char c)
{
    if (c == '\n')
    {
        cursor += 80 - (cursor % 80);
        return;
    }

    if (c == '\b')
    {
        if (cursor > 0) cursor--;
        vga[cursor] = (0x0F << 8) | ' ';
        return;
    }

    vga[cursor++] = (0x0F << 8) | c;
}

void print(const char* s)
{
    while (*s) print_char(*s++);
}

void clear()
{
    for (int i = 0; i < 80 * 25; i++)
        vga[i] = (0x0F << 8) | ' ';
    cursor = 0;
}
