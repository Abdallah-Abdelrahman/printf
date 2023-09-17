#include "main.h"
#include <stdio.h>
/**
 * _stoa - string pointer
 * @c: string
 * Return: string pointer
 */
char *_stoa(char *c)
{
	char *str = NULL;
	if(!c)
		c = "(null)";
	str = malloc((_strlen(c) + 1));
	_strcat(str,c);
	return (str);
}
/**
 * _ctoa - string pointer
 * @c: char
 * Return: string pointer
 */
char *_ctoa(char c)
{
	char *str = NULL;
	str = malloc(2);
	str[0] = c;
	str[1] = 0;
	return (str);
}
/**
 * _ptoa - percent string pointer
 * @c: char
 * Return: string pointer
 */

