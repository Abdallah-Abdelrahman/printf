#include "main.h"


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

	/*TODO: add functions for each specifier */
	_generic ptr[] = {
		{"c", (char *(*)(void)) _put_str},
		{"s", (char *(*)(void)) _put_str},
		{NULL, NULL}
	};

	while (ptr[i].c)
	{
		if (ptr[i].c[0] == c)
		{
			/*TODO: add cases for each specifier */
			switch (c)
			{
				case 'c':
					return ((((_int *)ptr)[i])
						.func(va_arg(ap, int)));
				case 's':
					return ((((_str *)ptr)[i])
						.func(va_arg(ap, char *)));
			}
		}
		i++;
	}

	/* incase non-matches */
	return (NULL);
}
