#include <stdio.h>
#include "monty.h"

/**
 * rotr - function tha rotates the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Reruen: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	stack_t *tmp = *stack;
	(void)line_number;

	if (node == NULL || node->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp = node;
	node->prev = tmp;
	node = tmp->prev;
	node->next = NULL;
	node->prev = NULL;
}

/**
 * rot1 - function that rotates the stack to the top
 * @stack: pointer to stack
 * @line_number: current line
 * Return: Nothing (void)
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	stack_t *tmp;

	(void)line_number;

	if (node == NULL || node->next == NULL)
		return;

	tmp = node;
	node = node->next;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = node->prev;
	node->prev = NULL;
	tmp->next->prev = tmp;
	tmp->next->next = NULL;
}
