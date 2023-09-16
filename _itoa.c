#include "main.h"
/**
 * _itoa - convert integer to string
 * @x: integer to convert to string
 * Return: converted string
 *
 */
char *_itoa(int x)
{
	int i = 0, neg = 0;
	char *y = NULL;
	if(x == 0)
	{
		y = _realloc(y, 0, 2);
		y[0] = '0';
		y[1] = '\0';
		return (y);
	}
	else if (x < 0)
	{
		neg = 1;
		x++;
		x = -x;
		i += 1;
		y = _realloc(y, 0, i);
		y[0] = x % 10 + 48 + 1;
		x = x / 10;
	}
	while (x > 0)
	{
		y = _realloc(y, i, i + 1);
		y[i] = x % 10 + 48;
		x /= 10;
		i++;
	}
	if (neg == 1)
	{
		y = _realloc(y, i, i + 1);
		y[i] = '-';
		i++;
	}
	y = _realloc(y, i, i + 1);
	y[i] = '\0';
	_rev_string(y);

	return (y);
}
