#include "main.h"

/**
 * _printf - prints text according to format
 * @format: string input includes formats and modifiers
 * Return: length of printed string
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int fi = 0, flag = 0, len = 0, buf = BUFF;
	char *res = NULL, *str = NULL, tc;

	if (!format || (format[0] == '%' && !format[1]) || !format[0])
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	res = _realloc(res, 0, buf);
	va_start(ap, format), res[0] = 0;
	while (format[fi])
	{
		if (format[fi] == '%')
			flag = 1, fi++;
		if (flag && format[fi] != '%')
		{
			str = get_formater(format[fi], ap, res);
			if (!str)
				return (-1);
			len = _strlen(str);
			if (len + _strlen(res) >= buf)
				buf += BUFF, res = _realloc(res, buf - BUFF, buf);
			_strcat(res, str), flag = 0;
			if (str)
				free(str);
		}
		else
		{
			if (1 + _strlen(res) >= buf)
			{
				buf += BUFF;
				res = _realloc(res, buf - BUFF, buf);
			}
			tc = (format[fi]);
			_strncat(res, &tc, 1), flag = 0;
		}
		fi++;
	}
	len = _strlen(res), _put_buffer(res, len), va_end(ap), free(res);
	return (len);
}
