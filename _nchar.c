#include "main.h"
/**
 * _nchar - count of character up to the point %n is called
 * @n: int pointer address
 * @res: result buffer
 * Return: nothing really
 */
void *_nchar(int *n, char *res)
{
	*n = _strlen(res);
	return (malloc(0));
}

