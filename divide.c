#include <stdio.h>
#include "monty.h"
/**
 * divide - function that divides the second top element
 * of the stack by the top element
 * @stack: Pointer to the stack
 * @line_number: line number
 * Return: Nothing
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;

	if (element == NULL || element->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (element->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	element->next->n /= element->n;
	pop(stack, line_number);
}
