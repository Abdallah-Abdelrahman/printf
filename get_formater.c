#include "main.h"

/**
 * get_formater - call the corresponding function,
 * based on the specifier passed to it.
 * @c: specifier
 * @ap: variable argument pointer
 * @res: result buffer
 * Return: string pointer
 */
char *get_formater(char c, va_list ap, char *res)
{
	int i = 0;
	(void)res;

	_generic gen[] = {{"c", (void(*)(void))_ctoa}, {"i", (void(*)(void))_itoa},
		{"d", (void(*)(void))_itoa}, {"s", (void(*)(void))_stoa},
		{"u", (void(*)(void))_utoa}, {"o", (void(*)(void))_otoa},
		{"x", (void(*)(void))_xtoa}, {"X", (void(*)(void))_Xtoa},
		{"b", (void(*)(void))_btoa}, {"r", (void(*)(void))_rtoa},
		{"R", (void(*)(void))_Rtoa}, {"S", (void(*)(void))non_printable},
		{"p", (void(*)(void))_ptoa}, {"n", (void(*)(void))_nchar},
		{NULL, NULL},
	};
	while (gen[i].c && gen[i].c[0])
	{
		if (c == gen[i].c[0])
		{
			switch (c)
			{
				case 'd': case 'i':
					return ((((_int *)gen)[i]).func(va_arg(ap, int)));
				case 's': case 'S': case 'r': case 'R':
					return ((((_str *)gen)[i]).func(va_arg(ap, char *)));
				case 'c':
					return ((((_char *)gen)[i]).func(va_arg(ap, int)));
				case 'u': case 'o': case 'x': case 'X':
				case 'b':
					return ((((_ui *)gen)[i]).func(va_arg(ap, unsigned int)));
				case 'p':
					return ((((_v *)gen)[i]).func(va_arg(ap, void *)));
				case 'n':
					return ((((_ip *)gen)[i]).func(va_arg(ap, int *), res));

			}
		}
		i++;
	}
	exit(100);
}

