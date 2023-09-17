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

	/*TODO: add ur functions, that handle conversions here */
	_generic gen[] = {
		{"c", (void(*)(void))_ctoa},
		{"i", (void(*)(void))_itoa},
		{"d", (void(*)(void))_itoa},
		{"s", (void(*)(void))_stoa},
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
				case 'd':
					return (((_int *)gen)[i]).func(va_arg(ap, int));
				case 'c':
					return (((_char *)gen)[i]).func(va_arg(ap, int));
					/* Removed case '%', handled in the _printf*/
			}
		}

		i++;
	}

	return (NULL);
}
