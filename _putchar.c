#include "main.h"

/**
 * _putchar - prints 1 byte
 * @c: character to print
 *
 * Return: number of bytes written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
