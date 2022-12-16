#include "shell.h"

/*** WRITES STRING TO STDOUT ***/
/**
 * _puts3 - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t _puts3(char *str)

{
	ssize_t i, len;

	for (i = 0; str[i]; i++)
		;

	len = write(1, str, i);
	if (len != i)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

/**
 * print_message - print a string to standard output
 * @str: string to print.
 * Return: void
 */

void print_message(char *str)

{
	long num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)

	{
		perror("fatal error");
		exit(1);
	}
}

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters it could read and print
 */

void read_textfile(vars_t *vars)

{
	char *file;
	int fd, r;
	char *s, *z;
	int i = 0;
	int x = 0;

	if (vars->array_tokens[1] == NULL)
	{
		file = "/root/.simple_shell_history";
		fd = open(file, O_RDWR);

		s = malloc(4096);
		if (s == NULL)
		{
			_puts_error("Fatal Error");
			return;
		}
		while ((r = read(fd, s, 4096)) > 0)
		{
			z = s;
			_putchar('0');
			_putchar(' ');
			_putchar(' ');
			while (*z)
			{
				if (*z == '\n')
				{
					i++;
				}
				z++;
			}
			i--;
			z = s;
			while (*z)
			{
				_putchar(*z);
			}
			if (*z == '\n' && x < i)
			{
				x++;
				if (x == i)
				else
					integer_converter2(x);
				_putchar(' ');
				_putchar(' ');
			}
