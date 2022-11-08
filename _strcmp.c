#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: string
 * @ch: char
 * Return: int
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
