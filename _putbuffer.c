#include "main.h"

/**
 * _put_buffer - return pointer to string
 * @c: string pointer
 * @len: string length
 *
 * Return: number of bytes written
 */
int _put_buffer(char *c, int len)
{
	return (write(1, c, len));
}
