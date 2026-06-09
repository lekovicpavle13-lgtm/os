#include "scheduler.h"

#define MAX_TASKS 16

task_t tasks[MAX_TASKS];
int current_task = 0;

void scheduler_init()
{
    for(int i = 0; i < MAX_TASKS; i++)
        tasks[i].active = 0;
}

void schedule()
{
    current_task++;

    if(current_task >= MAX_TASKS)
        current_task = 0;

    while(!tasks[current_task].active)
    {
        current_task++;

        if(current_task >= MAX_TASKS)
            current_task = 0;
    }
}

