#include "main.h"

/**
 * get_pf_func - selects the correct function to perform the operation
 * @s: character to be checked from the options below
 * Return: pointer to the chosen function by the given operator
 */

int (*get_pf_func(const char *s))(va_list list)
{
	pf_t op[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_per},
		{'i', print_integer},
		{'d', print_integer},
		{00, 00},
	}; /* This is the array of function pointers, basically. */
	int i = 0;

	while (i < 5)
	{
		if (*s == op[i].cha) /* If the entry char (string, oof) is
				      * equal to the indicator, executes its
				      * corresponding function
				      */
			return (op[i].f);
		i++;
	}
	return (op[i].f);
}
