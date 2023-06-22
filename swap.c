#include <stdio.h>
#include "monty.h"

/**
 * swap - function that swaps the top2 elements of the stack
 * @stack: head of the stack - linked list
 * @line_number: line number
 * Return: Void (Nothing)
 */
void swap(stack_t **stack, unsigned int line number)
{
	int temp_n;
	stack_t *node = *stack;

	if (node == NULL || stack->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_n = node->n;
	node->n = node->next->n;
	node->next->n = temp_n;
}
