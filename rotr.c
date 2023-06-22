#include <stdio.h>
#include "monty.h"

/**
 * rotr - function that rotates the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Reruen: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	stack_t *tmp = *stack;
	(void)line_number;

	if (tmp == NULL || tmp->next == NULL)
		return;

	node = tmp->next;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	(*stack)->next = NULL;
	*stack = tmp;
	(*stack)->prev = NULL;

	if (node != NULL)
		node->prev = NULL;
}

/**
 * rotl - function that rotates the stack to the top
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

	tmp->next = *stack;
	(*stack)->prev = tmp;
	(*stack)->next = NULL;
	(*stack) = node;
	(*stack)->prev = NULL;
}
