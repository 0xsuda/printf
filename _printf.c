#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include "main.h"
/**
 * _printf -function that produces output according to a format.
 * @format: The number of paramters
 * @...: A variable number of paramters
 * Return: int
 */
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
void print_number(int n);
void handle_char(va_list args);
void handle_string(va_list args);
void handle_integer(va_list args);
void handle_decimal(va_list args);
void handle_unsigned(va_list args);
void handle_hex(va_list args);
void handle_octal(va_list args);
void handle_binary(va_list args);
void handle_percentage(va_list args);

typedef struct {
    char specifier;
    void (*handler)(va_list);
} conversion_handler;

void handle_char(va_list args) {
    char c = va_arg(args, int);
    _putchar(c);
}

void handle_string(va_list args) {
    char *s = va_arg(args, char *);
    while (*s != '\0') {
        _putchar(*s++);
    }
}

void handle_integer(va_list args) {
    int num = va_arg(args, int);
    print_number(num);
}

void handle_decimal(va_list args) {
    double num = va_arg(args, double);
    printf("%f", num);
}

void handle_unsigned(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    print_number(num);
}

void handle_hex(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    printf("%x", num);
}

void handle_octal(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    printf("%o", num);
}

void handle_binary(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    int i;
    for ( i = 31; i >= 0; i--) {
        _putchar((num & (1 << i)) ? '1' : '0');
    }
}

void handle_percentage(va_list args) {
    (void)args;
    _putchar('%');
}

conversion_handler handlers[] = {
    {'c', handle_char},
    {'s', handle_string},
    {'d', handle_integer},
    {'i', handle_integer},
    {'f', handle_decimal},
    {'u', handle_unsigned},
    {'x', handle_hex},
    {'X', handle_hex},
    {'o', handle_octal},
    {'b', handle_binary},
    {'%', handle_percentage},
};

int _printf(const char *format, ...) {   
int count = 0;
    va_list args;
    char conversion_specifier;
    long unsigned int i;

    if (format == NULL)
        return -1;

    va_start(args, format);

    while ((conversion_specifier = *format++) != '\0') {
        if (conversion_specifier == '%') {
            conversion_specifier = *format++;
            for (i = 0; i < sizeof(handlers) / sizeof(conversion_handler); i++) {
                if (handlers[i].specifier == conversion_specifier) {
                    handlers[i].handler(args);
                    count++;
                    break;
                }
            }
        } else {
            _putchar(conversion_specifier);
            count++;
        }
    }

    va_end(args);
    return count;
}
