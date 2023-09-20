#include "main.h"

/**
 * non_printable - write your short description
 * @s: string pointer
 * Return: 0 as exit status
 */
char *non_printable(char *s)
{
	int len = 0, i = 0, idx = 0, buf = BUFF;
	char *ptr = 0, *hex = 0, c;

	if (!s || !s[0])
		s = "(null)";
	ptr = _realloc(ptr, i, buf);
	for (idx = 0; s && s[idx]; idx++, i++)
	{
		c = s[idx];
		ptr = ((i >= buf) ? _realloc(ptr, buf, buf + BUFF) : ptr);
		buf = i >= buf ? buf + BUFF : buf;
		ptr[i] = c;
		if ((c > 0 && c < 32) || c >= 127)
		{
			hex = _Xtoa((unsigned int)c);
			len = _strlen(hex);
			ptr[i++] = 92; /* '\\' */
			ptr[i++] = 120; /* 'x' */
			if (len < 2)
				ptr[i] = 48; /* '0' */
			_strcat(ptr, hex);
			i += len;
			if (hex)
				free(hex);
		}
		ptr = ((i >= buf) ? _realloc(ptr, buf, buf + BUFF) : ptr);
		buf = i >= buf ? buf + BUFF : buf;
		if (!ptr)
		{
			free(ptr);
			return (NULL);
		}
	}
	ptr[i] = 0;
	ptr = _realloc(ptr, buf, i + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}
