#include "shell.h"

/**
 * input_check - function that checks user input
 *
 * @input: user input
 * @interact_mode: shell interaction
 *
 * Return: void
 */

void input_check(char *input, int interact_mode)
{
	/* Remove newline character */
	size_t input_length = 0;

	while (input[input_length] != '\n' && input[input_length] != '\0')
		input_length++;
	/* exiting prompt, in the case of user inputting 'exit' */
	int inp_exit = (input_length == 4 && input[0] == 'e' && input[1] == 'x'
			&& input[2] == 'i' && input[3] == 't');

	if (inp_exit)
		return;

	/* Forking a child process */
	pid_t pid = fork();

	if (pid < 0)
	{
		write(STDERR_FILENO, "Fork failure\n", 12);
	}
	else if (pid == 0)
	{
		/* child process */
		char *inp_args[] = {input, NULL};

		execve(input, inp_args, NULL);
		/*write(STDERR_FILENO, "$ ", 2);*/
		write(STDERR_FILENO, input, input_length);
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		_exit(1);
	}
	else
	{
		/* parent process */
		wait(NULL);
		/*write(STDOUT_FILENO, "$ ", 2);*/
	}
}
