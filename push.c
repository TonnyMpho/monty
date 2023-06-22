#include <stdio.h>
#include <ctype.h>
#include "monty.h"

int is_num(const char *check);
/**
 * push - function that pushes an element on top of the stack
 * @stack: ponter to the head of the stack
 * @line_number: line number
 * Return: Void (nothing)
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	int num = 0;
	stack_t *new_node, *node = *stack;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (arg == NULL || !is_num(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(arg);

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = node;

	if (node != NULL)
		node->prev = new_node;

	*stack = new_node;
}

/**
 * is_num - function that check if the argument is a number
 * @check: number to check
 * Return: 0 or 1 not a number
 */
int is_num(const char *check)
{
	int i = 0;

	if (check == NULL || *check == '\0')
		return (0);

	if (check[0] == '-' || check[0] == '+')
		i++;

	for (; check[i] != '\0'; i++)
	{
		if (!isdigit(check[i]))
			return (0);
	}

	return (1);
}
