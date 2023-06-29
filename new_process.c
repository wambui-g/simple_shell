#include "shell.h"
#include <libgen.h>

/**
 * _strcmp- compare strings
 * @str1: first string
 * @str2: second string
 *
 * Return: int
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * new_process - create a new process
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int new_process(char **args)
{
	pid_t pid;
	int status;
	char *is_exit = "exit";
	/*char *error = ": command not found\n";*/
	/*const char *prog_name = basename(args[0]);*/

	if (args[0] == NULL)
		return (-1);

	if (_strcmp(args[0], is_exit) == 0)
		exit(EXIT_SUCCESS);

	pid = fork();

	if (pid ==  0)
	{
		if (execvp(args[0], args) == -1)
		{
			/*write(STDERR_FILENO, prog_name, sizeof(prog_name));*/
			/*write(STDERR_FILENO, ": ", 2);*/
			write(STDERR_FILENO, args[0], sizeof(args));
			perror(" ");
			exit(EXIT_FAILURE);
		}
		else
			handle_path(args);
	}
	else if (pid < 0)
	{
		perror("Fork failure\n");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
