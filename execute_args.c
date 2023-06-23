#include "shell.h"

/**
 * execute_args - execute arguements
 * @args: commands
 *
 * Retuen: 1 for success
 */
int execute_args(char **args)
{
	int new;

	if (args[0] == NULL)
		return (-1);
	else
	{
		new = new_process(args);
		return (new);
	}
}
