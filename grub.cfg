#include <stdint.h>

static uint32_t heap_start = 0x01000000;
static uint32_t heap_ptr = 0x01000000;

void* kmalloc(int size)
{
    uint32_t addr = heap_ptr;
    heap_ptr += size;
    return (void*)addr;
}
