#include "main.h"

/**
 * _putbuffer - return pointer to string
 * @c: string pointer
 * @len: string length
 *
 * Return: number of bytes written
 */
int _putbuffer(char *c, int len)
{
	return (write(1, c, len));
}
