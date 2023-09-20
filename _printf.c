#include "main.h"
#include <stdio.h>


/**
 * format_tester - tests the format str
 * @format: string input includes formats and modifiers
 * Return: 0 failure, 1 passed
 */

int format_tester(const char *format)
{
	if (!format || (format[0] == '%' && format[1] == 0) || format[0] == 0)
		return (0);
	if (format[0] == '%' && format[1] == ' ' && format[2] == 0)
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
	int  len = 0, buf = BUFF, nul = 0;
	char *res = NULL;

	if (!format_tester(format))
		exit(100);
	res = _realloc(res, 0, buf);
	if (!res)
		exit(100);
	va_start(ap, format), res[0] = 0;
	res = _make_result(format, res, ap, buf, &nul);
	if (!res)
		exit(100);
	len = _strlen(res) + nul, _put_buffer(res, len), va_end(ap), free(res);
	return (len);
}
/**
 * _make_result - prepares the result pointer for printing
 * @format: string input includes formats and modifiers
 * @res: result pointer
 * @ap: variable argument list
 * @buf: size of buffer
 * @nul: null byte char counter
 * Return: length of printed string
 */
char *_make_result(const char *format, char *res,
		va_list ap, int buf, int *nul)
{
	int len = 0, fi = 0, flag = 0;
	char *str, tc;

	while (format[fi])
	{
		str = NULL;
		if (format[fi] == '%')
			flag = 1, fi++;
		if (flag && format[fi] != '%')
		{
			str = flag_handler((char *)format, &fi, ap, res, nul);
			if (!str)
			{
				if (res)
					free(res);
				return (NULL); }
			len = _strlen(str);
			if (len + _strlen(res) >= buf)
				buf += BUFF, res = _realloc(res, buf - BUFF, buf);
			if (!res)
			{
				if (str)
					free(str);
				return (NULL); }
			_strcat(res, str),
				flag = 0;
			if (str)
				free(str); }
		else
		{
			if (1 + _strlen(res) >= buf)
			{
				buf += BUFF;
				res = _realloc(res, buf - BUFF, buf);
			}
			tc = (format[fi]);
			_strncat(res, &tc, 1), flag = 0; }
		fi++; }
	return (res);
}

/**
 * flag_handler - handler
 * @format: format pointer
 * @fi: format cursor
 * @ap: argument pointer
 * @res: result pointer
 * @nul: null byte char counter
 * Return: modified pointer to string
 */
char *flag_handler(char *format, int *fi, va_list ap, char *res, int *nul)
{
	int modifier;
	char *fptr = 0;

	fptr = get_flag((char *)(format + *fi), fi);
	modifier = get_modifier((char *)(format + *fi), fi);
	res = get_formater(format[*fi], ap, res, nul);
	if (fptr || modifier)
		res = justify(format[*fi], modifier, fptr, res);
	if (fptr)
		free(fptr);
	return (res);
}
