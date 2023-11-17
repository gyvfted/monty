#include "monty.h"
/**
 * tokenize - Tokenize a string into an array of strings
 * @lineptr: The string to be tokenized
 *
 * This function takes a string and tokenizes
 *  it based on specified delimiters.
 * It returns an array of strings (tokens)
 *  representing the individual elements
 * of the original string.
 *
 * Return: An array of strings representing
 *  the tokens, or NULL on failure.
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
