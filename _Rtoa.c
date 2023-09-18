#include "main.h"
/**
 * rot13 - function that encodes a string using rot13.
 *		can only use one if and 2 loops
 *		cant use switch
 * @s: string to encode
 * Return: s
 */
char *rot13(char *s)
{
	int i = 0, m;
	char c;

	while (*(s + i) != '\0')
	{
		c = *(s + i);
		m = *(s + i) / 32;
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		{
			*(s + i) = (m * 32 + 1) + (((*(s + i) - (m * 32 + 1) + 13) % 26));
		}
		i++;
	}
	return (s);
}
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
	l = _strlen(str);
	str = _realloc(str, 0, l + 1);
	str[0] = 0;

	_strcpy(str, rot13(s));
	return (str);
}



