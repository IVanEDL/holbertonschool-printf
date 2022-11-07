#include "main.h"

/**
 * _strlenpf - returns the length of a string, like the actual command
 * @s: char type variable
 * Return: length of the string
 */

int _strlenpf(char *s)
{
	int length;

	for (length = 0; s[length] != '\0'; length++)
	{}
	return (length);
}
