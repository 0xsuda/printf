#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * find_print_function - Find the print function for a given format specifier.
 * @format: The format specifier.
 *
 * Return: A pointer to the appropriate print function, or NULL if not found.
 */
int (*find_print_function(const char *format))(va_list)
{
unsigned int i = 0;
print_func find_func[] = {
{"c", print_cha},
{"s", print_str},
{"i", print_integer},
{"d", print_decimal},
{NULL, NULL}
};
while (find_func[i].specifier)
{
if (find_func[i].specifier[0] == (*format))
return (find_func[i].func);
i++;
}
return (NULL);
}
/**
 * _printf - Print formatted output.
 * @format: The format string.
 *
 * Return: The number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
va_list args;
int (*print_func)(va_list);
unsigned int i = 0, count = 0;
if (format == NULL)
return (-1);
va_start(args, format);
while (format[i])
{
while (format[i] != '%' && format[i])
{
_putchar(format[i]);
count++;
i++;
}
if (format[i] == '\0')
return (count);
print_func = find_print_function(&format[i + 1]);
if (print_func != NULL)
{
count += print_func(args);
i += 2;
continue;
}
if (!format[i + 1])
return (-1);
_putchar(format[i]);
count++;
if (format[i + 1] == '%')
i += 2;
else
i++;
}
va_end(args);
return (count);
}
