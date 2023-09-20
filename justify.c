#include "main.h"

/**
 * justify - write your short description
 * @s: specifier
 * @m: modifier length
 * @f: flag
 * @arg: converted string
 *
 * Return: 0 as exit status
 */
char *justify(char s, int m, char *f, char *arg)
{
	int i = 0;
	char *ptr = arg;
	_fc fc = {0, 0, 0, 0};

	for (i = 0; f && f[i]; i++)
	{
		switch (f[i])
		{
			case '#':
				if (fc.h || fc.s || fc.p)
					return (NULL);
				fc.h = 1, ptr = flag_hash(arg, s == 'o' ? 0 : 1);
				break;
			case '-':
				if (fc.n)
					return (NULL);
				fc.n = 1;
				break;
			case '+':
				if (fc.p || fc.s || fc.h)
					return (NULL);
				fc.p = 1,  ptr = (flag_plus(arg));
				break;
			case ' ':
				if (fc.s || fc.p || fc.h)
					return (NULL);
				fc.s = 1;
				ptr = (flag_space(arg));
				break;
			default:
				return (NULL);
		}
	}
	if (m)
		ptr = pad(ptr, m, !fc.n);
	return (ptr);
}

/**
 * pad - write your short description
 * @buf: buffer
 * @n: padding length
 * @flag: 1 positive, 0 otherwise
 *
 * Return: string pointer
 */
char *pad(char *buf, int n, int flag)
{
	int len = 0, i = 0, res = _strlen(buf);
	char *ptr = 0;

	n = n - res;
	ptr = _realloc(ptr, 0, BUFF);

	for (i = 0; i < n && n > res; i++)
	{
		ptr[i] = ' ';
	}
	ptr[i] = 0;
	if (flag)
	{
		ptr = _strcat(ptr, buf);
		if (buf)
			free(buf);
		len = _strlen(ptr);
		ptr = _realloc(ptr, BUFF, len + 1);

	}
	else
	{
		buf = _strcat(buf, ptr);
		len = _strlen(buf);
		buf = _realloc(buf, BUFF, len + 1);

	}

	return (ptr);
}

/**
 * get_flag - check for flags
 * Description: check fo these flags `+, -, ' ', #`,
 * and then increment the length of buffer when found.
 * @addr: address after '%'
 * @idx: current cursor of buffer
 *
 * Return: pointer to flags,
 * NULL otherwise.
 */
char *get_flag(char *addr, int *idx)
{
	int i = *idx, j = 0, flag = 1;
	char *f = 0;

	f = _realloc(f, 0, BUFF);
	for (i = 0; addr && addr[i] && flag;  i++)
	{
		switch (addr[i])
		{
			case '+':
			case '#':
			case '-':
			case ' ':
				*idx += 1;
				f[j] = addr[i];
				break;
			default:
				flag = 0;
				break;
		}
	}
	f[j++] = 0;
		f = _realloc(f, BUFF, j + 1);
	return (f);
}

/**
 * power - power
 * @x: base
 * @y: power
 *
 * Return: power
 */
int power(int x, int y)
{
	if (y == 0)
		return (1);
	while (--y)
	{
		x *= x;
	}
	return (x);
}
/**
 * get_modifier - check to see if there's any modifiers length
 * Description: modifiers range 0-9
 * @fmt: format
 * @idx: current cursor of format
 *
 * Return: modifier on success,
 * 0 otherwise.
 */
int get_modifier(char *fmt, int *idx)
{
	int m = 0, i = 0, j = 0, d;

	while (_isdigit(fmt[i]))
	{
		i++;
		*idx += 1;
	}
	while (i)
	{
		d = fmt[j] - 48;
		m += d * power(10, i - 1);
		i--;
		j++;
	}

	return (m);
}


