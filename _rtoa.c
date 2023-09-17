#include "main.h"
/**
 * _rtoa - function that reverses a string.
 * @s: pointer to a string.
 */
char *_rtoa(char *s)
{
	char *str = NULL;
	int  l = 0;

	if (!s)
		s = "(null)";
	l = _strlen(s);
	str = _realloc(str, 0, l + 1);
	str[0] = 0;
	_rev_string(s);
	_strcpy(str, s);
	return (str);
}
