#include "shell.h"

/**
 * read_stream - read a line from input
 *
 * Return: pointer that points the the read line
 */
char *read_stream(void)
{
	int bufsize = 1024, i = 0, j = 0, character;
	char *input = malloc(sizeof(char) * bufsize);
	char *temp;

	if (input == NULL)
	{
		perror("Memory Allocation Error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = read(STDIN_FILENO, input, sizeof(input));
		if (character == EOF)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			input[i] = '\0';
			return (input);
		}
		else
			input[i] = character;
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			temp = malloc(sizeof(char) * bufsize);
			if (temp == NULL)
			{
				perror("Memory Allocation Error\n");
				exit(EXIT_FAILURE);
			}
			for (; j < i; j++)
				temp[j] = input[j];
			free(input);
			input = temp;
		}
	}
}

