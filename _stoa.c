#include "main.h"

/**
 * _stoa - string pointer
 * @c: string
 * Return: string pointer
 */
char *_stoa(char *c)
{
	char *s = NULL;

	if (!c)
		c = "(null)";
	s = _realloc(s, 0, _strlen(c));
	s[0] = 0;
	_strcat(s, c);
	return (s);
}
/**
 * _ctoa - string pointer
 * @c: char
 * Return: string pointer
 */
char *_ctoa(char c)
{
	char *str = NULL;

	str = _realloc(str, 0, 2);
	str[0] = c;
	str[1] = 0;
	return (str);
}
