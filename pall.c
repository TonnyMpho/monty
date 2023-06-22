#include <stdio.h>
#include "monty.h"

/**
 * pall - function that prints all the nodes of the stack
 * @stack: pointer to the stack
 * @line_number: current line
 * Return: Void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
