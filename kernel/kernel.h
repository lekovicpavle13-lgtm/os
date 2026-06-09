#pragma once
#include <stdint.h>

/* ===== VGA / OUTPUT ===== */
void print(const char* s);
void print_char(char c);
void clear(void);

/* ===== SHELL ===== */
void shell_handle_char(char c);
void run_command(char* cmd);

/* ===== MEMORY HELPERS (optional later) ===== */
int strcmp(const char* a, const char* b);
int strlen(const char* s);

