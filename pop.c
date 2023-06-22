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
	stack_t *node = *stack;
	stack_t *tmp = *stack;

	if (node)
	{
		node = node->next;
		if (node)
			node->prev = NULL;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
