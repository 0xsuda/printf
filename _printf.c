#include "main.h"
/**
* _printf -function that produces output according to a format.
* @format: The number of paramters
* @...: A variable number of paramters
* Return: int
*/
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
if (!format)
return -1;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
count += _putchar(va_arg(args, int));
else if (*format == 's')
count += _puts(va_arg(args, char *));
else if (*format == '%')
count += _putchar('%');
}
else
count += _putchar(*format);
format++;
}
va_end(args);
return count;
}
