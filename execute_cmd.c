#include "shell.h"

/**
 * exec_cmd - argument handling with exit functionality
 *
 * @cmd: command to be executed in CLI
 *
 * Return: 0 for success, otherwise -1
 */

int exec_cmd(char *cmd)
{
	pid_t pid;
	int status;
	char *args[];

	pid = fork();

	if (pid == -1)
	{
		perror("Fork failure");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[] = { "/bin/sh", "-c", cmd, NULL };

		execvp(args[0], args);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		return (status);
	}
}
