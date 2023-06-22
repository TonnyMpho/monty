#include <stdlib.h>
#include "monty.h"

/**
 * push - functionthat pushes an element on top of the stack
 * @stack ponter to the head of the stack
 * @ine_number: line number
 * Return: Void (nothing)
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	int num;
	stack_t *new_node, *node = *stack;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!isdigit(arg[0]) && arg[0] != '-' && arg[0] != '+')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(arg);

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = node;

	if (node != NULL)
		node->prev = new_node;

	node = new_node;
}
