#include "main.h"
#include <unistd.h>

/**
 * _put_str - print string
 * @str: string pointer
 *
 * Return: pointer to string,
 * `(null)` in case of `NULL` pointer
 */
void _put_str(char *str)
{
	write(1, str, 1);
#if 0
	if (!str)
		return ("(null)");

	return (str);
#endif
}
