#include "main.h"
/**
 * _btoa - convert unsigned integer to binary
 * @n: unsigned int number
 * Return: string pointer
 */
char *_btoa(unsigned int n)
{
	unsigned int i = 0;
	char *ptr = NULL;

	if (n <= 1)
	{
		ptr = _realloc(ptr, 0, 2);
		ptr[0] = (n % 2) + 48;
		ptr[1] = 0;
		return (ptr);
	}
	ptr = _realloc(ptr, 0, BUFF);
	for (; n > 0; i++, n /= 2)
		ptr[i] = (n % 2) + 48;
	ptr[i] = 0;
	ptr = _realloc(ptr, BUFF, i + 1);
	_rev_string(ptr);
	return (ptr);
}
