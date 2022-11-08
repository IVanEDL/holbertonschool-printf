#include "main.h"

/**
 * _printf - prints given text and variables
 * @format: initial string of characters to be printed
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, p = 0;
	va_list list;
	int (*f)(va_list list);
	char *aux = "cisd%";

	va_start(list, format);
	if (format)
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] != 37)
			{
				write(1, &format[i], 1);
				p++;
			}
			else if (format[i] == 37)
			{
				if (_strcmp(aux, format[i + 1]) >= 0)
				{
					f = get_pf_func(&format[i + 1]);
					p += f(list);
					i++;
				}
				else if (format[i + 1] == 00)
					return (-1);
				else
				{
					write(1, &format[i], 1);
					p++;
				}
			}
		}
	}
	va_end(list);
	return (p);
}
