#include <stdio.h>
#include "monty.h"

/**
 * pint - function that prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: current line
 * Return: Void (Nothing)
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", node->n);
}
