#include "monty.h"

global_t glob = {NULL, NULL, NULL};

/**
 * main - Entry point
 * @ac: argc
 * @av: argv
 *
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t r = 0;
	stack_t *stack = NULL;
	unsigned int c = 0;

	if (ac != 2)
		usage_err();
	file = fopen(av[1], "r");
	if (file == NULL)
		file_err(av[1]);
	glob.file = file;
	while ((r = getline(&line, &len, file)) != -1)
	{
		line[strcspn(line, "\n")] = '\0';
		glob.line = line;
		c++;
		if (r != 0)
			parser(file, line, &stack, c);
	}
	free(line);
	freeStack(stack);
	fclose(file);
	return (0);
}
