#define _GNU_SOURCE
#include <stdio.h>
#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument array
 * Return: 0 (Success) or 1
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *buffer, *opcode;
	FILE *file;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buffer, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(buffer, " \t\n");
		if (opcode != NULL && opcode[0] != '#')
			execute_opcode(opcode, &stack, line_number);
	}

	free_stack(&stack);
	fclose(file);
	free(buffer);
	exit(EXIT_SUCCESS);
}
