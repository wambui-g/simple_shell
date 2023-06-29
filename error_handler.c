#include "shell.h"

/**
 * error_handler - handles errors passed in the shell
 *
 * @prog_name: name of command passed
 * @arg: arguments passed
 *
 * Return: void
 */

void error_handler(const char *prog_name, const char *arg)
{
	const char *err_msg = ": 1: %s: not found\n";
	char *buffer;
	size_t buffer_size = _strlen(prog_name) + _strlen(arg) + _strlen(err_msg) - 2;

	buffer = malloc(buffer_size);

	if (buffer == NULL)
	{
		perror("Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	snprintf(buffer, buffer_size, err_msg, arg);
	dprintf(STDERR_FILENO, "%s%s", prog_name, buffer);

	free(buffer);
	exit(EXIT_FAILURE);
}
