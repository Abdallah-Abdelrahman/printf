#include "main.h"
#include <stdarg.h>
/**
 * format_tester - tests the format str
 * @format: string input includes formats and modifiers
 * Return: 0 failure, 1 passed
 */

int format_tester(const char *format)
{
	if (!format || (format[0] == '%' && !format[1]) || !format[0])
		return (0);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (0);
	return (1);
}
/**
 * _printf - prints text according to format
 * @format: string input includes formats and modifiers
 * Return: length of printed string
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int  len = 0, buf = BUFF;
	char *res = NULL;

	res = _realloc(res, 0, buf);
	if (!res || !format_tester(format))
		return (-1);
		va_start(ap, format), res[0] = 0;
		res = _make_result(format, res, ap, buf);
		if (!res)
			return (-1);
		len = _strlen(res), _put_buffer(res, len), va_end(ap), free(res);
	return (len);
}

/**
 * _make_result - prepares the result pointer for printing
 * @format: string input includes formats and modifiers
 * @res: result pointer
 * @ap: variable argument list
 * @buf: size of buffer
 * Return: length of printed string
 */
char *_make_result(const char *format, char *res, va_list ap, int buf)
{
	int	len = 0, fi = 0, flag = 0;
	char *str = NULL, tc;

	while (format[fi])
	{
		if (format[fi] == '%')
			flag = 1, fi++;
		if (flag && format[fi] != '%')
		{
			str = get_formater(format[fi], ap, res);
			if (!str)
			{
				free(res);
				return (NULL);
			}
			len = _strlen(str);
			if (len + _strlen(res) >= buf)
				buf += BUFF, res = _realloc(res, buf - BUFF, buf);
			if (!res)
			{
				free(str);
				return (NULL);
			}
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
	return (res);
}
