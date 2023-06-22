#include <stdio.h>
#include "monty.h"

/**
 * mod - functiom that multiplies thr top two elements
 * @stack: pointer to the satck
 * @line_number: the current line
 * Return: Nothing (void)
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_SUCCESS);
	}

	if (node->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	node->next->n %= node->n;
	pop(stack, line_number);
}
