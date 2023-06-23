#include "shell.h"

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

	pid = fork();

	if (pid ==  0)
	{
		if (execvp(args[0], args) == -1)
		{
			/*perror("No such file or directory");*/
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
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
