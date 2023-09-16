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

### THe Argument List


### Percent


### Width



### Filling Extra Space



### Left & Right Justify Option



### The Zero-Fill Option



### Plus, minus, space, and Zero



### Printing Strings



### Floating Point
