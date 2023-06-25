#include "shell.h"

/**
 * parse_line- split a string into multiple strings
 * @input: string to be splited
 *
 * Return: pointer that points to the new array
 */
char **parse_line(char *input)
{
	int bufsize = 64;
	int j = 0, i = 0, capacity = bufsize;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;
	char **temp;

	if (!tokens)
	{
		/* perror("Arguement split error\n"); */
		exit(EXIT_FAILURE);
	}
	token = strtok(input, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;

		tokens[i] = token;
		i++;
		if (i >= capacity)
		{
			capacity += bufsize;
			temp = malloc(capacity * sizeof(char *));
			if (!temp)
			{
				/*perror("Allocation Error\n");*/
				exit(EXIT_FAILURE);
			}
			for (; j < i; j++)
				temp[j] = tokens[j];
			free(tokens);
			tokens = temp;
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
