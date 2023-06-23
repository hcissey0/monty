#include "monty.h"

/**
 * freeStack - frees a stack
 * @stack: the stack head
 */
void freeStack(stack_t *stack)
{
	stack_t *ptr, *tmp;

	ptr = stack;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}

/**
 * parser - parses the command
 * @file: the file
 * @line: the line of the instruction
 * @stack: the head of the stack
 * @c: the line_number
 */
void parser(FILE *file, char *line, stack_t **stack, unsigned int c)
{
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(line, "\n\t ");
	glob.arg = strtok(NULL, "\n\t ");
	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, c);
			return;
		}
		i++;
	}
	if (opcode != NULL && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", c, opcode);
		fclose(file);
		free(line);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_int - checks if a string is integer
 * @str: the string
 * Return: 0 if true 1 otherwise
 */
int check_int(char *str)
{
	size_t i = 0;

	for (; i < strlen(str); i++)
	{
		if (str[i] == '-')
			continue;
		if (str[i] < 48 || str[i] > 57)
			return (1);
	}
	return (0);
}
