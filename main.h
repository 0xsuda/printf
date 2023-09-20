#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
int _putchar(char c);
int _printf(const char *format, ...);
int print_cha(va_list c);
int print_str(va_list s);
int print_integer(va_list i);
int print_decimal(va_list d);
int print_rev(va_list r);
int print_bin(va_list b);
int print_unsig(va_list u);
int print_octal(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_rot13(va_list R);
/**
  * struct code_format - format
  *
  * @specifier: specifiers
  * @func: function
  */
typedef struct code_format
{
char *specifier;
int (*func)(va_list);
} print_func;

#endif
