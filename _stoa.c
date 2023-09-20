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
	s = _realloc(s, 0, _strlen(c) + 1);
	if (!s)
		return (NULL);
	s[0] = 0;
	_strcat(s, c);
	return (s);
}
/**
 * _ctoa - string pointer
 * @c: char
 * @nul: null byte char counter
 * Return: string pointer
 */
char *_ctoa(char c, int *nul)
{
	char *str = NULL;

	if (c)
	{
		str = _realloc(str, 0, 2);
		str[0] = c;
		str[1] = 0;
	}
	else
	{
		(*nul)++;
		str = _realloc(str, 0, 1);
		str[0] = 0;
	}
	return (str);
}
