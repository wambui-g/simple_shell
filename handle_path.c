#include "shell.h"

/**
 * handle_path - handles path
 *
 * Return: void
 */
void handle_path(void)
{
	char *command_path = NULL;
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");

	while (dir != NULL)
	{
		char file_path[1024];
		snprintf(file_path, sizeof(file_path), "%s%s", dir, command);
		if (access(file_path, X_OK) == 0)
		{
			command_path = strdup(file_path);
			break;
		}
		dir = strtok(NULL, ":");
	}
	if (command_path != NULL)
	{
		execve(command_path, arguements, NULL);
		perror("Execve failed");
		_exit(1);
	}
	else
	{
		perror("command not found\n")
		_exit(1);
	}
}
