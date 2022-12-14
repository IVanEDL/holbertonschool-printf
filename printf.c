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
			if (format[i] != 37) /*If the character isn't a %...*/
			{
				write(1, &format[i], 1); /*It prints it*/
				p++;
			}
			else /*But if it is*/
			{
				if (_strcmp(aux, format[i + 1]) >= 0)
				{
					f = get_pf_func(&format[i + 1]);
					p += f(list);
					i++;
				} /*Executes a corresponding function*/
				else if (format[1] != '\0')
				{
					write(1, &format[i], 1);
					p++;
				} /*A bit of hardcode, ngl. A mere % fails.*/
				else
				{
					va_end(list);
					return (-1);
				}
			}
		}
	}
	va_end(list);
	if (p == 0)
		return (-1); /*If the counter failed or no input was made*/
	return (p);
}
