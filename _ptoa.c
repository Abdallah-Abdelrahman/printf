#include "main.h"
#include <stdio.h>
/**
 * _ptoa - pointer address
 * @addr: void * to address
 * Return: string pointer
 */
char *_ptoa(void *addr)
{
	int i = 0;
	char *y = NULL;
	unsigned long pc = (unsigned long)addr, zero = 0;

	if (!addr)
	{
		y = _realloc(y, BUFF, 6);
		y[0] = 0;
		_strcat(y, "(nil)");
		return (y);
	}
	y = _realloc(y, 0, BUFF);
	if (!y)
		return (NULL);
	y[0] = 0;
	while (pc > 0)
	{
		y[i++] = pc % 16 < 10 ? pc % 16 + 48 : pc % 16 + 87;
		pc /= 16;
	}
	y[i++] = 'x';
	y[i++] = '0';
	y[i++] = 0;
	y = _realloc(y, BUFF, i);
	if (!y)
		return (NULL);
	_rev_string(y);
	return (y);
}


