#include "main.h"

/**
 * _putchar - prints 1 byte
 * @c: character to print
 * Return: number of bytes written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _put_1024 - prints 1024 bytes
 * @s: string to print
 * Return: number of bytes written
 */
int _put_1024(char *s)
{
	return (write(1, s, 1024));
}
