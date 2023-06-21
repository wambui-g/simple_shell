#include "shell.h"

/**
 * read_line - read a line from stdin
 *
 * Return: pointer that points to a str with the line content
 */
char *read_line(void)
{
	char *input = NULL;
	size_t bufsize = 0;

	if (getline(&input, bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(0);
		}
		else
		{
			free(input);
			perror("Error reading input\n");
			exit(1);
		}
	}
	return (input);
}
