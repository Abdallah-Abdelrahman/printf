#include "main.h"

void _frees_buff(int n, ...)
{
	int i;
	va_list ap;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		free(va_arg(ap, void *));
	}


}

