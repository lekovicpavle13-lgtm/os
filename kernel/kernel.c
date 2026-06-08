// Cleaned up duplicate/merged kernel implementation
#include <stdint.h>
#define MAX_CMD 128
#include "kernel.h"

static char cmd_buffer[MAX_CMD];
static int cmd_index = 0;

void idt_init();
void pic_remap();
void print(const char*);
void clear();
void print_char(char);

void run_command(char* cmd)
{
    if (cmd[0]=='h')
        print("\nhelp: help, clear, echo, sysinfo\n");

    else if (cmd[0]=='c')
        clear();

    else if (cmd[0]=='e')
        print("\necho: working\n");

    else if (cmd[0]=='s')
        print("\nPavleOS v0.1 - 32bit GRUB kernel\n");

    else
        print("\nunknown command\n");

    print("\n> ");
}


void shell_handle_char(char c)
{
    if (c == '\n')
    {
        cmd_buffer[cmd_index] = 0;

        print("\n");
        run_command(cmd_buffer);

        cmd_index = 0;
        return;
    }

    if (c == '\b')
    {
        if (cmd_index > 0)
        {
            cmd_index--;
            print_char('\b');
        }
        return;
    }

    if (cmd_index < MAX_CMD - 1)
        cmd_buffer[cmd_index++] = c;
    print_char(c);
}

void kernel_main()
{
    clear();

    print("PavleOS Shell v0.2\n");
    print("Type 'help'\n\n> ");

    idt_init();
    pic_remap();

    asm volatile ("sti");

    while (1)
    {
        asm volatile ("hlt");
    }
}

int strlen(const char* s)
{
    int i = 0;
    while (s[i]) i++;
    return i;
}

int strcmp(const char* a, const char* b)
{
    int i = 0;
    while (a[i] && b[i])
    {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return a[i] == b[i];
}