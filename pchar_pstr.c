#include <stdio.h>
#include "monty.h"

/**
 * pchar - function that prints the character
 * representation of the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Current line number
 * Return: Void (nothing)
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	if (node == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}

/**
 * pstr - function prints the string contained in the stack
 * @stack: pointer to the stack
 * @line_number: Current line
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	while (node != NULL && node->n != 0)
	{
		if (node->n < 0 || node->n > 127)
			break;

		putchar(node->n);
		node = node->next;
	}

	putchar('\n');
}
