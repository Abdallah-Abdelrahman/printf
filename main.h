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
int _putchar(char);
void _puts(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_itoa(int x);
int _put_1024(char *s);
void _rev_string(char *s);
int _strlen(char *s);
char *_strcat(char *dest, char *src);

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
