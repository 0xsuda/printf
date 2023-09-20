#include "main.h"

/**
 * print_integer - Print an integer
 * @args: The argument list containing the integer to print
 *
 * Return: The number of characters printed.
 */
int print_integer(va_list args)
{
  int len, powten, j,digit,  n, num, count = 0;
n = va_arg(args, int);
if (n != 0)
{
 if (n < 0)
{
_putchar('-');
count++;
}
num = n;
len = 0;
while (num != 0)
{
num /= 10;
len++;
}
powten = 1;
for (j = 1; j <= len - 1; j++)
{
powten *= 10;
}
while (len > 0)
{
digit = n / powten;
if (n < 0)
{
_putchar((digit * -1) + '0');
}
else
{
_putchar(digit + '0');
}
count++;
n -= digit * powten;
powten /= 10;
len--;
}
}
else
{
_putchar('0');
return (1);
}
return (count);
}
/**
 * print_decimal - Print a decimal integer
 * @args: The argument list containing the decimal integer to print
 *
 * Return: The number of characters printed.
 */
int print_decimal(va_list args)
{
int len, powten, j, digit, n, count = 0, num;
n = va_arg(args, int);
if (n != 0)
{
if (n < 0)
{
_putchar('-');
count++;
}
num = n;
len = 0;
while (num != 0)
{
num /= 10;
len++;
}
powten = 1;
for (j = 1; j <= len - 1; j++)
{
powten *= 10;
}
while (len > 0)
{
digit = n / powten;
if (n < 0)
{
_putchar((digit * -1) + '0');
}
else
{
_putchar(digit + '0');
}
count++;
n -= digit * powten;
powten /= 10;
len--;
}
}
else
{
_putchar('0');
return (1);
}
return(count);
}
