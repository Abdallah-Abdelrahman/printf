#include "main.h"
/**
 * _otoa - convert unsigned integer to octal string
 * @x: unsigned integer to convert to octal string
 * Return: converted string
 *
 */
char *_otoa(unsigned int x)
{
	unsigned int i = 0;
	char *y = NULL;

	if (x == 0)
	{
		y = _realloc(y, 0, 2);
		y[0] = 48;
		y[1] = 0;
		return (y);
	}
	y = _realloc(y, 0, BUFF);
	while (x > 0)
	{
		y[i] = x % 8 + 48;
		x = x / 8;
		i++;
	}
	y[i] = 0;
	y = _realloc(y, BUFF, i + 1);
	_rev_string(y);
	return (y);
}
