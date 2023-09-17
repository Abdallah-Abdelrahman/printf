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
		y[0] = '0';
		y[1] = '\0';
		return (y);
	}
	while (x > 0)
	{
		y = _realloc(y, i, i + 1);
		y[i] = x % 8 + 48;
		x /= 8;
		i++;
	}
	y = _realloc(y, i, i + 1);
	y[i] = '\0';
	_rev_string(y);

	return (y);
}
