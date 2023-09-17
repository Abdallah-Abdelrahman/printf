#ifndef HEADER
#define HEADER
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/* Important! Delete comment!! */
/* #include <stdio.h> */
#define BUFF 1024


/* your protos goes here */
int _put_buffer(char *, int);
int _printf(const char *, ...);
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
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_stoa(char *c);
char *_ctoa(char c);
char *_utoa(unsigned int x);
char *_otoa(unsigned int x);
/**
 * struct _character - char struct
 * @func: function pointer
 */
typedef struct _character
{
	char *c;
	char *(*func)(char);
} _char;
/**
 * struct _integer - integer struct
 * @func: function pointer
 */
typedef struct _integer
{
	char *c;
	char *(*func)(int);
} _int;
/**
 * struct _string - string struct
 * @func: function pointer
 */
typedef struct _string
{
	char *c;
	char *(*func)(char *);
} _str;
/**
 * struct _double - double struct
 * @func: function pointer
 */
typedef struct _double
{
	char *c;
	char *(*func)(double);
} _lf;
/**
 * struct _generic - generic struct
 * @func: function pointer
 */
typedef struct _generic
{
	char *c;
	void (*func)(void);
} _generic;


#endif /* HEADER */
