#include "monty.h"

/**
 * stack - changes to stack
 * @stack: the stack
 * @line_number: the line number
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	glob.sq = 1;
}

/**
 * queue - changes the stack to queue
 * @stack: the stack
 * @line_number: the line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	glob.sq = 0;
}
