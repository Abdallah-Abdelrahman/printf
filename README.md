# Printf Mock Implementation

## Notes 

## Simple Printing

In the most simple case, printf takes one argument: a string of characters to be printed. This string is composed of characters, each of which is printed exactly as it appears. So printf("xyz"); would simply print an x, then a y, and finally a z.


### Naturally Special Characters
To identify the start of the string, we put a doublequote (") at the front. To identify the end of the string we put another double-quote at the end. But what if we want to actually print a double-quote? We can’t exactly put a double-quote in the middle of the string because it would be mistaken for the end-of-string marker. Double-quote is a special char- acter. The normal print-what-you-see rules do not apply.

#### List of Special Characters

| Character | Escaped Character |
| --------  | -------			|
| \		    | \\\				|
| "		    | \\"				|
| '		    | \\'				|
| %		    | \\%				|
| newline	| \\n				|
| tab		| \\t				|
| Null byte	| \\0				|

### Alternately Special Characters
On the other hand we have characters that normally print as you would expect, but when you add a backslash, then they become special. An example is the newline character. To print an n, we simply type in an n. To print a newline, we type in a \n, thus invoking the alternate meaning of n, which is newline. 

#### List of Alternately Special Characters
| Character | Description			|
| --------  | -------				|
| \a		|  audible alert (bell)	|
| \b		| backspace				|
| \f		| form feed				|
| \n	    | newline (linefeed)	|
| \r		| carriage return		|
| \t		| tab					|
| \v		| vertical tab			|


## Format Specifications
The real power of printf is when we are printing the contents of variables. Let’s take the format specifier %d for example. This prints a number. So, a number must be provided for printing. This is done by adding another argument to the printf statement, as shown here.
```
int age;
age = 25;
printf ( "I am %d years old\n", age );
```
In this example, printf has two arguments. The first is a string: "I am %d years old\n". The second is an integer, age.



### Percent and Format Specifiers
When an argument is to be printed by printf, there must be an percentage sign `%` preceeding the format specifier, modifiers (flags, field width, precision, and length modifiers).

- Flags: Control the alignment and representation of the output (e.g., %-10d for left-justified integer).
- Field Width: Specify the minimum width of the output field (e.g., %5d for a minimum width of 5 characters).
- Precision: Control the number of decimal places for floating-point numbers (e.g., %.2f for two decimal places).
- Length Modifiers: Specify the size of the argument (e.g., %ld for a long integer).

##### Below is a list of the format specifiers handled in this project.

- %c: prints a character
- %s: prints a string
- %%: prints a percent sign `%`
- %d: prints a decimal (base 10) number
- %i: prints an integer number
- %b: prints a binary number from an unsigned int
- %u: prints an unsigned int
- %o: prints an octal number from an unsigned int
- %x: prints a hexadecimal number in lower case from an unsigned int
- %X: prints a hexadecimal number in upper case from an unsigned int
- %S: prints a string while converting any Non printable characters (0 < ASCII value < 32 or >= 127) in this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
- %p: prints an address
- %r: prints a string in reverse
- %R: prints the rot13'ed string

### Flags

- `-`: Left-justify the result within the field width. It is right justified by default.
- `+`: Prefix the output value with a sign (+ or -) if the output value is of a signed type. Only negative sign appears by default. 
- `space ' '`: Prefix the output value with a blank if the output value is signed and positive. The + flag overrides the blank flag if both appear, and a positive signed value will be output with a sign.
- `#`: It behaves differently depending on which specifier it is paired with:
	- When used with the o, x, or X formats, the # flag prefixes any nonzero output value with 0, 0x, or 0X, respectively.
	- When used with the p format, the # flag converts the pointer to hex digits. These hex digits cannot be converted back into a pointer, unless in a teraspace environment.
	- th `#` flag should not be used with c, lc, d, i, u, or s types.
- `0`: When used with the d, i, D(n,p) o, u, x, or X, the 0 flag causes leading 0s to pad the output to the field width. The 0 flag is ignored if precision is specified for an integer or if the - flag is specified.

### Width



### Filling Extra Space



### Left & Right Justify Option



### The Zero-Fill Option



### Plus, minus, space, and Zero



### Printing Strings



### Floating Point
