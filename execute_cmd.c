#include "shell.h"

/**
 * exec_cmd - argument handling with exit functionality
 *
 * @cmd: command to be taken in CLI
 *
 * Return: void
 */

void exec_cmd(char *cmd)
{
	char *args[] = {0};

	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = cmd;
	args[3] = NULL;

	if (execve(args[0], args, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
