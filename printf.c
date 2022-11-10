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
	if (format) /*Checks if format is actually something*/
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] != 37) /*If it isnt a %...*/
			{
				write(1, &format[i], 1); /*Writes a character*/
				p++;
			}
			else if (format[i] == 37) /*But if it is...*/
			{
				if (_strcmp(aux, format[i + 1]) >= 0)
				/*Checks if the next character is compatible*/
				{
					f = get_pf_func(&format[i + 1]);
					p += f(list);
					i++;
				/* And executes a corresponding function */
				}
				else if (format[i + 1] != '\0')
				{
					write(1, &format[i], 1);
					p++;
				}
				else
					return (-1);
			}
		}
	}
	va_end(list);
	if (p == 0)
		return (-1); /*Returns -1 if the character counter didn't count anything*/
	return (p);
}
