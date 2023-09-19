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

	if (!s)
		s = "(null)";
	ptr = _realloc(ptr, i, buf);
	if (!ptr)
		return (NULL);
	for (idx = 0; s && s[idx]; idx++, i++)
	{
		c = s[idx];
		ptr = ((i >= buf) ? _realloc(ptr, buf, buf + BUFF) : ptr);
		if (!ptr)
			free(ptr), exit(98);

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
		ptr = ((i >= buf) ? _realloc(ptr, buf, buf + BUFF) : ptr);
		if (!ptr)
			free(ptr), exit(98);

	}
	ptr[i] = 0;
	ptr = _realloc(ptr, BUFF, i + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}
