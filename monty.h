#ifndef MONTY_H
#define MONTY_H

#define MAX 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - the global variabe
 * @file: the file pointer
 * @line: the line of instruction
 * @arg: the argument
 *
 * Descrition: global variable
 */
typedef struct global_s
{
	FILE *file;
	char *line;
	char *arg;
} global_t;

extern global_t glob;

/* errors */
void usage_err(void);
void file_err(char *);
void malloc_err(void);
void opcode_err(int, char *);
/* opcode errors */
void push_err(unsigned int);

/* opcode funcs */
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);

/* helper funcs */
void freeStack(stack_t *);
void parser(FILE *, char *, stack_t **, unsigned int);

#endif /* MONTY_H */
