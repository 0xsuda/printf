#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
* print_str - Print a string to stdout
* @args: The argument list containing the string to print
* Return: The number of characters printed.
*/
int print_str(va_list args)
{
char *str;
int i = 0;
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
for (i = 0; str[i]; i++)
{
_putchar(str[i]);
}
return (i);
}
