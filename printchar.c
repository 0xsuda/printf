#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_cha - print   char
 * @c:value print char
 *
 * Return: 1.
 */
int print_cha(va_list c)
{
	unsigned char cha;

	cha = va_arg(c, int);
	_putchar(cha);
	return (1);
}
/**
 * print_percen - print %
 *
 * Return: 1.
 */
int print_percen(void)
{
	_putchar('%');
	return (1);
}
