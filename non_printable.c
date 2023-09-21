#include "main.h"

/**
 * non_printable - write your short description
 * @s: string pointer
 * Return: 0 as exit status
 */
char *non_printable(char *s)
{
	int i = 0, idx = 0, buf = BUFF;
	int c;
	char *ptr = 0;

	if (!s || !s[0])
		s = "(null)";
	ptr = _realloc(ptr, i, buf);
	for (idx = 0; s && s[idx]; idx++)
	{
		c = s[idx];
		if ((c > 0 && c < 32) || c >= 127)
		{
			make_printable(ptr, &i, c);
			continue;
		}
		ptr[i++] = c;
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

/**
 * make_printable - make non_printable printable!
 * @ptr: result pointer
 * @i: pointer to counter
 * @c: non_printable character
 *
 */
void make_printable(char *ptr, int *i, int c)
{
	char *hex = _Xtoa(c);
	int len = _strlen(hex);

	ptr[(*i)++] = 92; /* '\\' */
	ptr[(*i)++] = 120; /* 'x' */
	if (len < 2)
		ptr[(*i)++] = 48; /* '0' */
	ptr[(*i)] = 0;
	_strcat(ptr, hex);
	(*i) += len;
	if (hex)
		free(hex);
	hex = 0;
}
