#include "main.h"
/**
 * rot13 - function that encodes a string using rot13.
 * Description: can only use one if and 2 loops
 * cant use switch
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
 * _Rtoa - function that returns encoded string using rot13.
 * @s: pointer to a string.
 * Return: str
 */
char *_Rtoa(char *s)
{
	char *str = NULL;
	int  l = 0;

	if (!s)
		s = "(null)";
	l = _strlen(s);
	str = _realloc(str, 0, l + 1);
	str[0] = 0;
	_strcat(str, s);
	rot13(str);
	return (str);
}



