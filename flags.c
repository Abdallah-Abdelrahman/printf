#include "main.h"

/**
 * flag_hash - write your short description
 * @x: number to format
 * @flag: 1 for upper hex, 0 for lower
 *
 * Return: string pointer
 */
char *flag_hash(char *x, int flag)
{
	char *ptr = 0;

	if (flag)
	{
		ptr = _realloc(ptr, 0, 3 + _strlen(x));
		ptr[0] = '0';
		ptr[1] = 'x';
		ptr[2] = '\0';
	}
	else
	{
		ptr = _realloc(ptr, 0, 2 + _strlen(x));
		ptr[0] = '0';
		ptr[1] = '\0';
	}
	_strcat(ptr, x);

	return (ptr);
}

/**
 * flag_plus - write your short description
 * @x: number to format
 *
 * Return: string pointer
 */
char *flag_plus(char *x)
{
	char *ptr = 0;

	ptr = _realloc(ptr, 0, 2 + _strlen(x));
	ptr[0] = '+';
	ptr[1] = 0;
	_strcat(ptr, x);

	return (ptr);
}

/**
 * flag_space - write your short description
 * @x: number to format
 *
 * Return: string pointer
 */
char *flag_space(char *x)
{
	char *ptr = 0;

	ptr = _realloc(ptr, 0, 2 + _strlen(x));
	ptr[0] = ' ';
	ptr[1] = 0;
	_strcat(ptr, x);

	return (ptr);
}

