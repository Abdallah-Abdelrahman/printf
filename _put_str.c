#include "main.h"
#include <unistd.h>

/**
 * _put_str - print string
 * @str: string pointer
 *
 * Return: pointer to string,
 * `(null)` in case of `NULL` pointer
 */
char  *_put_str(char *str)
{
	if (!str)
		return ("(null)");

	return (str);
}
