#include <stdio.h>
#include "monty.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument array
 * Return: 0 (Success) or 1
 */
int main(int argv, char *argv[])
{
	stack_t *stack = NULL;
	char *buffer, opcode;
	FILE *file;
	ssize_t read_line;
	size_t len = 0;
	unsigned int line_number = 1;

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

	while ((read_line = getline(&buffer, &len, file)) != -1)
	{
		opcode = strtok(readline, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
		{
			line_number++;
			continue;
		}

		instru_opcode = execute_opcode(opcode);
		if (instru_opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		instru_opcode->f(&stck, line_number);
		line_number++;
	}

	free_stck(&stack);
	fclose(file);

	if (read_line)
		free(line);
	exit(EXIT_SUCCESS);
}
