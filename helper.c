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
		{"nop", nop}, {"sub", sub},
		{"div", divv}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {"stack", stacker},
		{"queue", queue},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode;

	opcode = strtok(line, "\n\t ");
	if (opcode && opcode[0] == '#')
		return;
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

/**
 * add_to_queue - addd and element to a queue
 * @queue: the queue
 * @n: the element
 */
void add_to_queue(stack_t **queue, int n)
{
	stack_t *ptr, *tmp;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
		malloc_err();
	ptr->n = n;
	ptr->prev = NULL;
	ptr->next = NULL;
	if (*queue == NULL)
		*queue = ptr;
	else
	{
		tmp = *queue;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ptr;
		ptr->prev = tmp;
	}
}

/**
 * add_to_stack - adds to the stack
 * @stack: the stack
 * @n: the element
 */
void add_to_stack(stack_t **stack, int n)
{
	stack_t *ptr;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
		malloc_err();
	ptr->n = n;
	ptr->prev = NULL;
	ptr->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = ptr;
	*stack = ptr;
}
