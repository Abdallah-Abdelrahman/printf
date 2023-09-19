#include "main.h"

/**
 * flag_hash - write your short description
 * @x: number to format
 * @flag: 1 for upper hex, 0 for lower
 *
 * Return: string pointer
 */
char *flag_hash(unsigned int x, int flag)
{
	unsigned int len = 0;
	char *ptr = 0, *tmp = 0;

	ptr = _realloc(ptr, 0, 3);
	ptr[0] = '0';
	ptr[1] = 'x';
	ptr[2] = '\0';
	tmp = flag ? _Xtoa(x) : _xtoa(x);
	_strcat(ptr, tmp);
	len = _strlen(ptr);
	ptr = _realloc(ptr, 3, len + 1);
	ptr[len] = 0;
	free(tmp);

	return (ptr);
}

/**
 * flag_plus - write your short description
 * @x: number to format
 *
 * Return: string pointer
 */
char *flag_plus(unsigned int x)
{
	unsigned int len = 0;
	char *ptr = 0, *tmp = 0;

	ptr = _realloc(ptr, 0, 2);
	ptr[0] = '+';
	ptr[1] = 0;
	tmp = _utoa(x);
	_strcat(ptr, tmp);
	len = _strlen(ptr);
	ptr = _realloc(ptr, 2, len + 1);
	ptr[len] = 0;
	free(tmp);

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
	free(x);

	return (ptr);
}

