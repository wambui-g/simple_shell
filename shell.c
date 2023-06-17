#include "shell.h"

/**
 * main - simple shell
 *
 * Return: 0 for  success
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char prompt[] = "$ ";
	size_t prompt_length = sizeof(prompt) - 1;

	while (1)
	{
		int interact_mode = isatty(STDIN_FILENO);

		write(STDOUT_FILENO, prompt, prompt_length);

		/* Read user input */
		ssize_t input_length = read(STDIN_FILENO, input, sizeof(input));

		/* check EoF (Ctrl + D) */
		if (input_length == 0)
			break;

		if (input_length == -1)
		{
			write(STDERR_FILENO, "Read failed\n", 12);
			break;
		}

		/* function for checking input */
		/* input_check(input, interactive_mode); */
	}
	return (0);
}
