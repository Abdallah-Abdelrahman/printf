#include "main.h"
#include <stdio.h>

/**
 * justify - write your short description
 * @s: specifier
 * @m: modifier length
 * @f: flag
 * @arg: converted string
 *
 * Return: 0 as exit status
 */
char *justify(char s, char m, char f, char *arg)
{
	char *ptr = arg;
	unsigned int x = atoi(arg);

	(void)m;

	printf("pad(m) = %c\n", m);
	switch (f)
	{
		case '#':
			ptr = (s == 'X' ? flag_hash(x, 1) : flag_hash(x, 0));
			break;
		case '+':
			ptr = (flag_plus(x));
			break;
		case ' ':
			ptr = (flag_space(x));
			break;
	}
	if (m)
	{
		ptr = pad(ptr, m - '0', f == '-' ? 0 : 1);

	}
	return (ptr);
}

/**
 * pad - write your short description
 * @buf: buffer
 * @n: padding length
 *
 * Return: string pointer
 */
char *pad(char *buf, int n, int flag)
{
	int len = 0, i = 0, res = _strlen(buf);
	char *ptr = 0;

	n = n - res;

	printf("pad = %d\n", n);
	ptr = _realloc(ptr, 0, BUFF);
	for (i = 0; i < n && n < res; i++)
	{
		ptr[i] = ' ';
	}
	ptr[i] = 0;
	if (flag)
		_strcat(ptr, buf);
	else
		_strcat(buf, ptr);
	len = _strlen(ptr);
	printf("ptr = %s, buf = %s\n", ptr, buf);
	ptr = _realloc(ptr, BUFF, len + 1);

	return (ptr);
}

/**
 * get_flag - check for flags
 * Description: check fo these flags `+, -, ' ', #`,
 * and then increment the length of buffer when found.
 * @c: flag
 * @idx: current cursor of buffer
 *
 * Return: flag on success,
 * 0 otherwise.
 */
char get_flag(char c, int *idx)
{
	char f = 0;

	switch (c)
	{
		case '+':
		case '#':
		case '-':
		case ' ':
			*idx += 1;
			return (c);
	}
	return (f);
}
/**
 * get_modifier - check to see if there's any modifiers length
 * Description: modifiers range 0-9
 * @c: character digit
 * @idx: current cursor of buffer
 *
 * Return: modifier on success,
 * 0 otherwise.
 */
char get_modifier(char c, int *idx)
{
	char m = 0;

	if (_isdigit(c))
	{
		*idx += 1;
		m = c;
	}

	return (m);
}
