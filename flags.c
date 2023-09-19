#include "main.h"

/**
 * flags - write your short description
 * @x: number to format
 * @specifier: format character
 *
 * Return: string pointer
 */
char *flags(unsigned int x, char specifier)
{
	char *ptr = malloc(0);

	switch (specifier)
	{
		case 'x':
			return (flag_hash(x, 0));
		case 'X':
			return (flag_hash(x, 1));
		case '+':
			return (flag_plus(x));
		case ' ':
			return (flag_space(x));
	}

	return (ptr);
}
/**
 * flag_space - write your short description
 * @x: number to format
 *
 * Return: string pointer
 */
char *flag_space(unsigned int x)
{
	unsigned int len;
	char *ptr = 0;

	ptr = _realloc(ptr, 0, 2);
	ptr[0] = ' ';
	ptr[1] = 0;
	_strcat(ptr, _utoa(x));
	len = _strlen(ptr);
	ptr = _realloc(ptr, 2, len + 3);
	ptr[len + 2] = 0;

	return (ptr);
}
/**
 * flag_hash - write your short description
 * @x: number to format
 *
 * Return: string pointer
 */
char *flag_hash(unsigned int x, int flag)
{
	unsigned int len;
	char *ptr = 0;

	ptr = _realloc(ptr, 0, 3);
	ptr[0] = '0';
	ptr[1] = 'x';
	ptr[2] = '\0';
	_strcat(ptr, flag ? _Xtoa(x) : _xtoa(x));
	len = _strlen(ptr);
	ptr = _realloc(ptr, 3, len + 4);
	ptr[len + 3] = 0;
	
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
	unsigned int len;
	char *ptr = 0;

	ptr = _realloc(ptr, 0, 2);
	ptr[0] = '+';
	ptr[1] = 0;
	_strcat(ptr, _utoa(x));
	len = _strlen(ptr);
	ptr = _realloc(ptr, 2, len + 1);

	return (ptr);
}
