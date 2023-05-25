#include "shell.h"

/**
 * _eputs - It Prints an input string.
 * @str: This is the string to be printed
 * Return: Returns Nothing 
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - It Writes the character c to stderr.
 * @c: c is the character to be printed
 *
 * Return: On success return 1.
 * On error, return -1, and err no is set appropriately
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - It writes the character c to given fd.
 * @c: c is the character to be printed.
 * @fd: It is the file descriptor to write to.
 *
 * Return: 1 on success.
 * On error, return -1, and errno is set appropriately
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Its function is to print an input string
 * @str: This is the string to be printed.
 * @fd: IT is the file descriptor to write to.
 *
 * Return: Returns the number of chars put.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
