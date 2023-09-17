#include <stdio.h>
/**
 * _printf -function that produces output according to a format.
 * @format: The number of paramters
 * @...: A variable number of paramters
 *
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
char *arg_s;
char arg_c;
int count = 0;
va_list args;
char conversion_specifiers;
va_start(args, format);
while ((conversion_specifiers = *format++) != '\0')
{
if (conversion_specifiers == '%')
{
switch (*format++)
{
case 'c':
arg_c = va_arg(args, int);
putchar(arg_c);
count++;
break;
case 's':
arg_s = va_arg(args, char *);
while (*arg_s != '\0')
{
putchar(*arg_s++);
count++;
}
break;
case '%':
putchar('%');
count++;
break;
default:
break;
}
}
else
{
putchar(conversion_specifiers);
count++;
}
}
va_end(args);
return (count);
}
