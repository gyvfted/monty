#include "monty.h"

/**
 * mult - Multiplies the second element from
 * the top with the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the operation in the Monty file.
 */
void mult(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * modu - Computes the modulo of the second element
 *  from the top with the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the operation in the Monty file.
 */
void modu(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - Prints the ASCII character of the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the operation in the Monty file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int char_value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	char_value = (*stack)->n;
	if (char_value < 0 || 127 < char_value)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)char_value);
}

/**
 * pstr - Prints the string starting from the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number of the operation in the Monty file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (temp == NULL)
	{
		printf("\n");
		return;
	}
	while (temp != NULL && temp->n != 0 && temp->n >= 0 && temp->n <= 127)
	{
		printf("%c", (char)temp->n);
		temp = temp->next;
	}
	printf("\n");
}
