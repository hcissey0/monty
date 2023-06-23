#include "monty.h"

/**
 * usage_err - prints a usage error
 */
void usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * file_err - prints file error
 * @file: file name
 */
void file_err(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * opcode_err - prints opcode error
 * @lnum: line number
 * @opcode: the opcode
 */
void opcode_err(int lnum, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", lnum, opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_err - prints malloc error
 */
void malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * exit_fail_safe - exits safe
 */
void exit_fail_safe()
{
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}
