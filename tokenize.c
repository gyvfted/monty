#include "monty.h"

/**
 * tokenize - tokenizes the lines of a monty script
 * @lineptr: a string full of arguments
 * Return: tokens of lineptr(array)
 */

char **tokenize(char *lineptr)
{
	char **argv = NULL, *token;
	char *lineptr_cp;
	int count = 0, i;

	if (lineptr == NULL)
		return (NULL);
	lineptr_cp = strdup(lineptr);
	if (lineptr_cp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(lineptr, DELIMITERS);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, DELIMITERS);
	}
	argv = malloc(sizeof(char *) * (count + 1));

	token = strtok(lineptr_cp, DELIMITERS);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, DELIMITERS);
	}
	argv[i] = NULL;
	free(lineptr_cp);
	return (argv);
}
