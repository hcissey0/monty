#include "monty.h"

/**
 * add - adds the top two
 * @stack: the stack
 * @line_number: the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * nop - doesn't do anything
 * @stack: the stack
 * @line_number: the line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top from the next top
 * @stack: the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int sub;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}

	sub = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sub;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * div - divides the second top by the top
 * @stack: the stack
 * @line_number: line number
 */
void div(stack_t **stack, unsigned int line_number)
{
	int div;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	div = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = div;

	tmp = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
