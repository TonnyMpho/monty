#include <stdio.h>
#include "monty.h"

/**
 * free_stack - function that frees the stack
 * @stack: - pointer to the stck
 * Return: Void
 */
void free_stack(stack_t **stack)
{
	stack_t *node;

	while (*stack != NULL)
	{
		node = *stack;
		*stack = (*stack)->next;
		free(node);
	}
}
