#include "main.h"
/**
 * _xtoa - convert unsigned integer to hex string
 * @x: unsigned integer to convert to hex string
 * Return: converted string
 *
 */
char *_xtoa(unsigned int x)
{
	unsigned int i = 0, r;
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
		r = x % 16;
		if (r > 9)
			r += 39;
		y[i] = r + 48;
		x /= 16;
		i++;
	}
	y = _realloc(y, i, i + 1);
	y[i] = '\0';
	_rev_string(y);

	return (y);
}
