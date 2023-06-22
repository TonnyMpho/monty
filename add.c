#include <stdio.h>
#include "monty.h"

/**
 * add - function that adds elements to the top
 * of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number
 * Return: Void (nothing)
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node->next->n += node->n;
	pop(stack, line_number);
}
