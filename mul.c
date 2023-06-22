#include <stdio.h>
#include "monty.h"

/**
 * mul - functiom that multiplies thr top two elements
 * @stck: pointer to the satck
 * @line: the current line
 * Return: Nothing (void)
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL || node->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_SUCCESS);
	}

	node->next->n *= node->n;
	pop(stack, line_number);
}
