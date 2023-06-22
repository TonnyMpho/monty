#include <stdio.h>
#include "monty.h"

/**
 * pop - function that removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: Void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
