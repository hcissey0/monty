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