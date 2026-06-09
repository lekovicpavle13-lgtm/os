
#pragma once
#include <stdint.h>

typedef struct {
    uint32_t esp;
    uint32_t ebp;
    uint32_t eip;
    int active;
} task_t;

void scheduler_init();
void schedule();
