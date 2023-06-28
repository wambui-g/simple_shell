#include "shell.h"

/**
 * handle_path - handles path
 * @args: array with arguements
 *
 * Return: void
 */
void handle_path(char **args)
{
	char *command_path = NULL;
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char file_path[1024];

	while (dir != NULL)
	{
		snprintf(file_path, sizeof(file_path), "%s%s", dir, args[0]);
		if (access(file_path, X_OK) == 0)
		{
			command_path = strdup(file_path);
			break;
		}
		dir = strtok(NULL, ":");
	}
	if (command_path != NULL)
	{
		execve(command_path, args, NULL);
		perror("Execve failed");
		_exit(1);
	}
	else
	{
		perror("command not found\n");
		_exit(1);
	}
}
