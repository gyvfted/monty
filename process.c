#include "monty.h"
/**
 * process - Process a file containing
 *  commands and execute them
 * @file: Pointer to the FILE structure
 *  representing the input file
 * @stack: Double pointer to the top of the stack
 *
 * This function reads lines from the
 * specified file, tokenizes each line,
 * and processes the tokens to execute c
 * orresponding commands.
 *
 * Return: EXIT_SUCCESS on successful
 * processing, EXIT_FAILURE otherwise.
 */
int process(FILE *file, stack_t **stack)
{
	char *lineptr = NULL;
	size_t n = 0;
	unsigned int line_number = 0;
	ssize_t line;
	size_t index;

	while ((line = getline(&lineptr, &n, file)) != -1)
	{
		line_number++;
		index = 0;
		while (lineptr[index] != '\0' && isspace(lineptr[index]))
			index++;
		if (lineptr[index] == '#')
			continue;
		if (line > 0 && lineptr[line - 1] == '\n')
			lineptr[line - 1] = '\0';
		tokens = tokenize(lineptr);
		if (tokens[0] != NULL)
		{
			match(tokens[0], stack, line_number);
		}
		free_tokens(tokens);
	}
	free(lineptr);
	if (feof(file))
	{
		return (EXIT_SUCCESS);
	}
	else
	{
		return (EXIT_FAILURE);

	}
}
