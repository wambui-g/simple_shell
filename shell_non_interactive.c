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
		args = parse_line(input); /* tokenize line */

		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(input);
				free(args);
				exit(EXIT_SUCCESS);
			}
			status = exec_cmd(args[0]);
		}
		/* avoid memory leaks */
		free(input);
		free(args);
	}
}
