#include "main.h"

/**
 * justify - write your short description
 * @c: specifier
 * @m: modifier
 * @f: flag
 * @arg: converted string
 *
 * Return: 0 as exit status
 */
char *justify(char c, char m, char f, char *arg)
{
	char *ptr = 0;
	unsigned int x = atoi(arg);

	switch (f)
	{
		case '#':
			 ptr = c == 'X' ? flag_hash(x, 1) : flag_hash(x, 0);
		case '+':
			return (flag_plus(x));
		case '-':
			/* TODO: work in progress */
			break;
		case ' ':
			ptr = (flag_space(x));
	}
	return (ptr);
}

