#include "main.h"

/**
 * test_int - integer
 * @c: int
 * Return: string pointer
 */
char *test_int(int c)
{
	(void)c;
	return ("");
}
/**
 * test_double - integer
 * @c: double
 * Return: string pointer
 */
char *test_double(double c)
{
	(void)c;
	return ("");
}
/**
 * test_str - string pointer
 * @c: double
 * Return: string pointer
 */
char *test_str(char *c)
{
	(void)c;
	return ("");
}
/**
 * get_formater - call the corresponding function,
 * based on the specifier passed to it.
 * @c: specifier
 * @ap: variable argument pointer
 *
 * Return: string pointer
 */
void *get_formater(char c, va_list ap)
{
	int i = 0;

	/*TODO: add ur functions, that handle conversions here */
	_generic ptr[] = {
		{"s", (void (*)(void)) test_str},
		{"f", (void (*)(void)) test_double},
		{"i", (void (*)(void)) test_int},
		{"c", (void (*)(void)) test_int},
		{NULL, NULL}
	};

	while (ptr[i].c)
	{
		if (ptr[i].c[0] == c)
		{
			/*TODO: add cases for each specifier */
			switch (c)
			{
				case 'i':
					return (((_int *)ptr)[i])
						.func(va_arg(ap, int));
				case 'c':
					return (((_int *)ptr)[i])
						.func(va_arg(ap, int));
				case 's':
					return (((_str *)ptr)[i])
						.func(va_arg(ap, char *));
				case 'f':
					return (((_lf *)ptr)[i])
						.func(va_arg(ap, double));
			}
		}
		i++;
	}

	/* incase non-matches */
	return (NULL);
}
