#include "main.h"
#include <stdarg.h>

/*
 * _printf - prints text according to format
 * @fmt: string input includes formats and modifiers
 * Return: length of printed string
 */

int _printf(const char *fmt, ...)
{
	va_list ap;
	int fi = 0, ri = 0,flag = 0, len = 0;
	unsigned int size = 0;
	char *res = NULL, *str = NULL;

	va_start(ap,fmt);
	while(fmt[fi])
	{
		if (fmt[fi] =='%')
		{
			flag = 1;
			fi++;
			continue;
		}
		if(flag)
		{
			switch (fmt[fi])
			{
				case 'c':
					res = _realloc(res,size + 1,size + 2);
					res[ri] = va_arg(ap, int);
					size++;
					flag = 0;
					res[ri + 1] = 0;

					break;
				case 's':
					str = va_arg(ap, char *);
					len  = _strlen(str);
					res = _realloc(res,size + 1,size + len + 1);
					_strcat(res, str);
					size += len;
					flag = 0;
					ri += len - 1;
					res[ri + 1] = 0;

					break;
				case 'i':
					str = _itoa(va_arg(ap, int));
					len  = _strlen(str);
					res = _realloc(res,size + 1,size + len + 1);
					_strcat(res, str);
					free(str);
					size += len;
					flag = 0;
					ri += len - 1;
					res[ri + 1] = 0;
					break;
				case 'd':
					str = _itoa(va_arg(ap, int));
					len  = _strlen(str);
					res = _realloc(res,size + 1,size + len + 1);
					_strcat(res, str);
					free(str);
					size += len;
					flag = 0;
					ri += len - 1;
					res[ri + 1] = 0;
					break;

				default:
					res = _realloc(res,size + 1,size + 2);
					res[ri] = fmt[fi];
					size++;
					flag = 0;
					res[ri + 1] = 0;
					break;
			}
		}
		else
		{
			res = _realloc(res,size + 1,size + 2);
			res[ri] = fmt[fi];
			res[ri + 1] = 0;

			size++;

		}
		fi++; ri++;
	}
	_puts(res);
	va_end(ap);
	free(res);
	return (size);
}
