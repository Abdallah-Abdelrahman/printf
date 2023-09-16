#include "main.h"

/**
 * _puts - function that  prints a string, followed by a new line, to stdout.
 * @s: pointer to a string.
 */
void _puts(char *s)
{
	while (*(s))
		_putchar(*s++);
}

