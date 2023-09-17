#include "main.h"
#include <stdio.h>
/**
 * _printf - prints text according to format
 * @fmt: string input includes formats and modifiers
 * Return: length of printed string
 */

int _printf(const char *fmt, ...)
{
	va_list ap;
	int fi = 0, flag = 0, len = 0, buf = BUFF;
	/* unsigned int size = 0; */
	char *res = NULL, *str = NULL, tc;
	res = _realloc(res, 0, BUFF);
	/* str = _realloc(str, 0, BUFF); */

	va_start(ap, fmt);
	while (fmt[fi])
	{
		if (fmt[fi] == '%')
		{
			flag = 1;
			fi++;
		}



		if (flag)
		{

			str = get_formater(fmt[fi],ap);
			/* len = _strlen(str); */
			if (len + _strlen(res) >= buf)
			{
				buf += BUFF;
				res = _realloc(res, buf - BUFF, buf);
			}
			_strcat(res, str);
			flag = 0;
		}
		else
		{
			tc = (fmt[fi]);
			_strncat(res, &tc, 1);
		}
			fi++;
	}
	_puts(res);
	va_end(ap);
	free(res);
	return (_strlen(res));
}
