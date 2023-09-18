#include "main.h"
/**
 * _ptoa - pointer address
 * @addr: void * to address
 * Return: string pointer
 */
char *_ptoa(void *addr)
{
	int i = 0;
	char *y = NULL;
	unsigned long pc = (unsigned long)addr;

	if (!addr)
		exit(-1);
	y = _realloc(y, 0, BUFF);
	while (pc > 0)
	{
		y[i++] = pc % 16 < 10 ? pc % 16 + 48 : pc % 16 + 87;
		pc /= 16;
	}
	y[i++] = 'x';
	y[i++] = '0';
	y[i++] = 0;
	y = _realloc(y, BUFF, i);
	_rev_string(y);
	return (y);
}

