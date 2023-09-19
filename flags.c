#include "main.h"

/**
 * get_flag - check for flags
 * Description: check fo these flags `+, -, ' ', #`,
 * and then increment the length of buffer when found.
 * @c: number to format
 * @len: address of buffer length
 *
 * Return: flag on success,
 * 0 otherwise.
 */
char get_flag(char c, int *len)
{
	char f = 0;

	switch (c)
	{
		case '+':
		case '#':
		case '-':
		case ' ':
			*len += 1;
			return (c);
	}
	return (f);
}
/**
 * get_modifier - check to see if there's any modifiers length
 * Description: modifiers range 0-9
 * @c: character to check
 * @len: address of buffer length
 *
 * Return: modifier on success,
 * 0 otherwise.
 */
char get_modifier(char c, int *len)
{
	char m = 0;

	if (_isdigit(c))
	{
		*len += 1;
		m = c;
	}

	return (m);
}
/**
 * flag_hash - write your short description
 * @x: number to format
 * @flag: 1 for upper hex, 0 for lower
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
/**
 * _isdigit - checks for a digit (0 through 9).
 * @c: charater to check.
 *
 * Return: 1 if c is digit, 0 otherwise.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

