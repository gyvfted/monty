#include "monty.h"

/**
 * free_tokens - Frees an array of tokens.
 * @tokens: The array of tokens to free.
 */
void free_tokens(char **tokens)
{
	int i;

	if (tokens != NULL)
	{
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);
	}
}

/**
 * free_stack - Frees a stack.
 * @stack: A pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
