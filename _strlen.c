#include <stddef.h>

/**
 * _strlen - length of a string
 *
 * @str: input string
 *
 * Return: length of calculated string
 */

size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
