#include <stdio.h>
#include "monty.h"
/**
 * sub - function that subtracts the top element of
 * the stack from the second
 * @stack: Pointer to the stack
 * @line_number: Current line number
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node->next->n -= node->n;
	pop(stack, line_number);
}
