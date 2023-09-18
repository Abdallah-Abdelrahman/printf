#include "main.h"
/**
 * _rtoa - function that reverses a string.
 * @s: pointer to a string.
 * Return: reversed string ptr
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
	_strcat(str, s);
	_rev_string(str);
	return (str);
}
