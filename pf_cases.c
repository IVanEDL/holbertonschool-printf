#include "main.h"

/**
 * print_char - prints a char
 * @list: received list
 * Return: number of characters printed
 */

int print_char(va_list list)
{
	char p = va_arg(list, int);

	_putchar(p);
	return (1);
}

/**
 * print_string - prints a string
 * @list: list of elements to be taken to print
 * Return: number of characters printed
 */

int print_string(va_list list)
{
	int x = 0, y = 0;
	char c;
	char *a;

	a = va_arg(list, char *);
	if (a == 00)
		a = "(null)";
	for (; a[x] != '\0'; x++)
	{
		c = a[x];
		_putchar(c);
		y++;
	}
	return (y);
}

/**
 * print_per - prints a %
 * @list: lists of attributes (unused)
 * Return: number of characters printed
 */

int print_per(va_list list __attribute__((unused)))
{
	_putchar('%');
	return (1);
}

/**
 * print_integer - prints an integer
 * @list: lists of attributes
 * Return: number of characters printed
 */

int print_integer(va_list list)
{
	char aux[64];
	long int a = va_arg(list, int);
	int p = 0, i = 63;

	if (a < 0)
	{
		_putchar('-');
		p++;
		a = -a;
		if (a >= 2147843600)
		{
			a += 48;
		}
	}
	aux[64] = '\0';
	if (a == 0)
	{
		_putchar(a + '0');
		p++;
	}
	for (; a != 0; i--)
	{
		aux[i] = a % 10;
		a = a / 10;
	}
	i++;
	for (; i < 64; i++)
	{
		_putchar(aux[i] + '0');
		p++;
	}
	return (p);
}
