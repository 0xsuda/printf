#ifndef ASMA
#define ASMA
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#define BUFFER_SIZE 1024
int _putchar(char c);
int _printf(const char *format, ...);
void print_number(int n);
void handle_char(va_list args);
void handle_string(va_list args);
void handle_perc(va_list args);
void handle_integer(va_list args);
void handle_decimal(va_list args);
#endif
