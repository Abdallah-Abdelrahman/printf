#ifndef HEADER
#define HEADER
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/* your protos goes here */
int _putbuffer(char *, int);
int _printf(const char *format, ...);
char *get_formater(char c, va_list ap);
char *_put_str(char *str);

/**
 * _int - integer struct
 * @func: function pointer
 */
typedef struct _integer
{
	char c;
	char *(*func)(int);
} _int;
/**
 * _str - string struct
 * @func: function pointer
 */
typedef struct _string
{
	char c;
	char *(*func)(char *);
} _str;
/**
 * _generic - generic struct
 * @func: function pointer
 */
typedef struct _generic
{
	char *c;
	char *(*func)(void);
} _generic;

#endif /* HEADER */
