#include "main.h"
#include <stdio.h>

/**
 * non_printable - write your short description
 * @s: string pointer
 *
 * Return: 0 as exit status
 */
char *non_printable(char *s)
{
	int len = 0, i = 0, idx = 0;
	char *ptr = 0, *hex = 0;

	ptr = _realloc(ptr, i, BUFF);
	for (idx = 0; s && s[idx]; idx++, i++)
	{
		char c = s[idx];

		ptr[i] = c;
		if ((c > 0 && c < 32) || c >= 127)
		{
			hex = _Xtoa(c);
			len = _strlen(hex);
			ptr[i++] = 92; /* '\\' */
			ptr[i++] = 120; /* 'x' */
			if (len < 2)
				ptr[i] = 48; /* '0' */

			_strcat(ptr, hex);
			i += len;
		}
	}
	ptr = _realloc(ptr, BUFF, i + 1);

	return (ptr);
}
