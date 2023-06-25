#include "monty.h"

/**
 * mod - the modulo of the second top and the top
 * @stack: the stack
 * @line_number: the line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int mod;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	mod = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = mod;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pchar - prints a character to stdout
 * @stack: the stack
 * @line_number: the line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints a string
 * @stack: the stack
 * @line_number: the line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	if (tmp->n < 1 || tmp->n > 127)
	{
		printf("\n");
		return;
	}
	else
		printf("%", tmp->n);
	printf("%c", tmp->n);
	while (tmp != NULL)
	{
		if (tmp->next == NULL || tmp->next->n < 1 || tmp->next->n > 127)
		{
			printf("\n");
			return;
		}
		printf("%c", tmp->next->n);
		tmp = tmp->next;
	}
}
