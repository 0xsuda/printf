#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include "main.h"
/**
 * _printf -function that produces output according to a format.
 * @format: The number of paramters
 * @...: A variable number of paramters
 *
 *
 * Return: int
 */
typedef struct {
char specifier;
void (*handler)(va_list);
} conversion_handler;

void handle_char(va_list args) {
char c = va_arg(args, int);
_putchar(c);
}
void handle_perc(va_list args) {
    (void)args;
    _putchar('%');
}
void handle_string(va_list args) {
char *s = va_arg(args, char *);
while (*s != '\0') {
_putchar(*s++);
}
}
conversion_handler handlers[] = {
{'c', handle_char},
{'s', handle_string},
{'%', handle_perc},
};
int _printf(const char *format, ...)
{
int  count = 0;
va_list args;
char conversion_specifier;
long unsigned int i ;
if (format == NULL)
return (-1);
va_start(args, format);
while ((conversion_specifier = *format++) != '\0') {
if (conversion_specifier == '%') {
conversion_specifier = *format++;
 for (i = 0; i < sizeof(handlers)/sizeof(conversion_handler); i++) {
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
return (count);
}
