#include "monty.h"

/**
 * push - pushes to a stack
 * @stack: the stack head
 * @line_number: the line number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *tmp;

	if (glob.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	tmp = malloc(sizeof(stack_t));
	if (tmp == NULL)
		malloc_err();
	if (check_int(glob.arg) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	n = atoi(glob.arg);
	while (*stack && (*stack)->prev)
		*stack = (*stack)->prev;
	tmp->n = n;
	tmp->prev = NULL;
	tmp->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = tmp;

	*stack = tmp;
}

/**
 * pall - prints the vals of a stack
 * @stack: points to the head of the stack
 * @line_number: the line number of the opcode
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	if (*stack == NULL)
		return;
	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - prints the value at the top
 * @stack: pointer to stack
 * @line_number: the line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - pops an element from the stack
 * @stack: the stack
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	ptr = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(ptr);
}

/**
 * swap - swaps the top two elements
 * @stack: the stack
 * @line_number: the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeStack(*stack);
		exit_fail_safe();
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
