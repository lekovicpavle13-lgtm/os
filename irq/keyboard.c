
#include "io.h"

extern void shell_handle_char(char c);

static char scancode_map[] =
{
    0,27,'1','2','3','4','5','6','7','8','9','0',
    '-', '=', '\b',
    '\t',
    'q','w','e','r','t','y','u','i','o','p',
    '[',']','\n',
    0,
    'a','s','d','f','g','h','j','k','l',';',
    '\'', '`',
    0,
    '\\','z','x','c','v','b','n','m',',','.','/'
};

void keyboard_handler_c()
{
    unsigned char sc = inb(0x60);

    if (sc > 58) return;

    char c = scancode_map[sc];

    shell_handle_char(c);
}
