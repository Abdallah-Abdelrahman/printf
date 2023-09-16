/**
 * _strcat - function that concatenates two strings
 *			by appending the src string to the dest string,
 *			overwriting the terminating null byte (\0)
 *			at the end of dest, and then adds a terminating
 *			null byte
 * @src: pointer to the source string.
 * @dest: pointer to the destination string.
 * Return: the pointer to destination.
 */
char *_strcat(char *dest, char *src)
{
	int l = 0, m = 0;

	while (dest[l])
	{
		l++;
	}
	while (src[m])
	{
		dest[l + m] = src[m];
		m++;
	}
	dest[l + m] = src[m];
	return (dest);
}
