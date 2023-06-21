#include "shell.h"

/**
 * shell_non_interactive - handle shell  in non-interactive mode
 *
 * Return: void
 */
void shell_non_interactive(void)
{
	char *input;
	char **args;
	int status = -1;

	while (status == -1)
	{
		input = read_stream();
		args = split_line(line); /* tokenize line */
		/* status = execute_args(args);*/
		/* avoid memory leaks */
		free(line);
		free(args);
		/* exit with status */
		if (status >= 0)
			exit(status);
	}
}
