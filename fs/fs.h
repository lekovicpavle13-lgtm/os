#pragma once

#define MAX_FILES 32
#define MAX_NAME 32
#define MAX_CONTENT 512

typedef struct {
    char name[MAX_NAME];
    char content[MAX_CONTENT];
    int used;
} file_t;

void fs_init();
void fs_list();
void fs_create(char* name);
void fs_write(char* name, char* data);
void fs_cat(char* name);
void fs_delete(char* name);

