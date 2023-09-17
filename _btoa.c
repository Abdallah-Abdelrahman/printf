#include "main.h"

/**
 * _btoa - convert unsigned integer to binary
 * @n: number
 *
 * Return: string pointer
 */
char *_btoa(unsigned int n)
{

	int i = 0;
	char *ptr = 0;

	ptr = _realloc(ptr, 0, BUFF);

	if (n == 0)
	{
		ptr[i] = 48;
		ptr[i + 1] = 0;
		ptr = _realloc(ptr, BUFF, i + 2);
		return (ptr);
	}
	for (; n > 0; i++, n /= 2)
		ptr[i] = (n % 2) + 48;
	ptr[i] = 0;
	ptr = _realloc(ptr, BUFF, i + 1);

	_rev_string(ptr);
	return (ptr);
}
