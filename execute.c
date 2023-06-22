#include <stdio.h>
#include "monty.h"

/**
 * execute_opcode - Executes the opcode function
 * @opcode: opcode command
 * @stack: headof the linked list - stack
 * @line_number: line number
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t opcode_instr[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"sub", sub}, {"div", divide},
		{"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr},
		{"rotl", rotl}, {"rotr", rotr},
		{"nop", nop}, {NULL, NULL}};

	unsigned int i = 0;

	while (opcode_instr[i].opcode != NULL)
	{
		if (strcmp(opcode, opcode_instr[i].opcode) == 0)
		{
			opcode_instr[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
