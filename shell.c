#include "shell.h"

/**
 * main - function that checks if our shell is called
 *
 * Return: 0 on success
 */
int main(void)
{
	char *input;
	char **args;
	int status = -1;

	if (isatty(STDIN_FILENO) == 1)
		shell_interactive();
	else
	{
		while (status == -1)
		{
			input = read_line();
			args = parse_line(input);
			status = new_process(args);

			free(input);
			free(args);

			if (status >= 0)
				exit(status);
		}
	}

	return (0);
}
