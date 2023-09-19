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
char conversion_specifiers;

if (format == NULL)
return (-1);

va_start(args, format);
while ((conversion_specifiers = *format++) != '\0') {
if (conversion_specifiers == '%') {
switch (*format++) {
case 'c': {
char arg_c = va_arg(args, int);
_putchar(arg_c);
count++;
break;
}
case 's': {
char *arg_s = va_arg(args, char *);
if (arg_s == NULL) {
char *null_str = "(null)";
while (*null_str != '\0') {
_putchar(*null_str++);
count++;
}
}
else
 {
while (*arg_s != '\0') {
_putchar(*arg_s++);
count++;
}
}
break;
}
case '%': {
_putchar('%');
count++;
break;
}
case 'd': {
int arg_d = va_arg(args, int);
print_number(arg_d);
count++;
break;
}
case 'i': {
int arg_i = va_arg(args, int);
print_number(arg_i);
count++;
break;
}
case 'f': {
double arg_f = va_arg(args, double);
printf("%f", arg_f);
count++;
break;
}
default:
break;
}
} else {
_putchar(conversion_specifiers);
count++;
}
}
va_end(args);
return (count);
}
