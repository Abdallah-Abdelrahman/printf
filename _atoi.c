#include "main.h"
/**
 * _atoi - converts string to an integer
 * @s: string pointer
 *
 * Return: 0 if there're no numbers in the string,
 * otherwise return the integer
 */
int _atoi(char *s)
{
	unsigned int num = 0, n_count = 0;

	while (*s)
	{
		if (*s == ';')
			break;
		if (*s == '-')
			n_count++;
		if (*s >= 48 && *s <= 57)
			num = (num * 10) + (*s - 48);
		s++;

	}

	return (n_count % 2 == 0 ? num : -num);
}
