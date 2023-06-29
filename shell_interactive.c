#include "shell.h"

/**
 * shell_interactive - handle shell in interactive mode
 *
 * Return: void
 */
void shell_interactive(void)
{
	char *input;
	char **args;
	int status = -1;
	char prompt[] = "$ ";

	while (status == -1)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
		input = read_line();
		args = parse_line(input);
		status = new_process(args);

		/* avoid memory leaks */
		free(input);
		free(args);

		/* exit with status */
		if (status >= 0)
			exit(status);
	}
}
