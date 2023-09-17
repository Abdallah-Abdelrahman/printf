#include "main.h"

/**
 * _printf - prints text according to format
 * @fmt: string input includes formats and modifiers
 * Return: length of printed string
 */

int _printf(const char *fmt, ...)
{
	va_list ap;
	int fi = 0, flag = 0, len = 0, buf = BUFF;
	char *res = NULL, *str = NULL, tc;

	res = _realloc(res, 0, buf);
	va_start(ap, fmt), res[0] = 0;
	if (!fmt)
		exit(98);
	while (fmt[fi])
	{
		if (fmt[fi] == '%')
			flag = 1, fi++;
		if (flag && fmt[fi] != '%')
		{
			str = get_formater(fmt[fi], ap);
			if (!_strcmp(str, "(null)"))
				exit(99);
			if (!str)
				exit(99);
			len = _strlen(str);
			if (len + _strlen(res) >= buf)
				buf += BUFF, res = _realloc(res, buf - BUFF, buf);
			_strcat(res, str), flag = 0, free(str);
		}
		else
		{
			if (1 + _strlen(res) >= buf)
			{
				buf += BUFF;
				res = _realloc(res, buf - BUFF, buf);
			}
			tc = (fmt[fi]);
			_strncat(res, &tc, 1), flag = 0;
		}
		fi++;
	}
	len = _strlen(res);
	_put_buffer(res, len);
	va_end(ap), free(res);
	return (len);
}
