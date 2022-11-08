#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @ch: entry char to compare
 * Return: ubication in the string of the compared char
 */

int _strcmp(char *s1, char ch)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == ch)
			return (i);
	}
	return (-1);
}
