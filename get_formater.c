#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * test_int - integer
 * @c: int
 * Return: string pointer
 */
char *test_int(int c)
{
	return (_itoa(c));
}
/**
 * test_double - integer
 * @c: double
 * Return: string pointer
 */
char *test_double(double c)
{
	(void)c;
	return ("double or float");
}
/**
 * test_str - string pointer
 * @c: double
 * Return: string pointer
 */
char *test_str(char *c)
{
	(void)c;
	return (c);
}
/**
 * test_str - string pointer
 * @c: double
 * Return: string pointer
 */
char *test_char(char c)
{
	char *str;
	str = malloc(sizeof(char) * 2);

	str[0] = c;
	str[1] = 0;

	return (str);
}
/**
 * get_formater - call the corresponding function,
 * based on the specifier passed to it.
 * @c: specifier
 * @ap: variable argument pointer
 *
 * Return: string pointer
 */
char *get_formater(char c, va_list ap)
{
	int i = 0;

	/*TODO: add ur functions, that handle conversions here */
	_generic gen[] = {
		{"c", (void(*)(void))test_char},
		{"i", (void(*)(void))test_int},
		{"f", (void(*)(void))test_double},
		{"s", (void(*)(void))test_str},
		{NULL, NULL},
	};

	while (gen[i].c && gen[i].c[0])
	{
		if (c == gen[i].c[0])
		{
			switch (c)
			{
				case 'i':
					return (((_int *)gen)[i]).func(va_arg(ap, int));
				case 's':
					return (((_str *)gen)[i]).func(va_arg(ap, char *));
				case 'f':
					return (((_lf *)gen)[i]).func(va_arg(ap, double));
				case 'c':
					return (((_int *)gen)[i]).func(va_arg(ap, int));
				case '%':
					return (((_int *)gen)[i]).func(va_arg(ap, int));
			}
		}

		i++;
	}

	return (NULL);
}
