#include "monty.h"
#include <stdio.h>

/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	MontyContext_t customContext = {NULL, NULL, NULL, 0};
	char *lineContent;
	FILE *montyFile;
	size_t size = 0;
	ssize_t readLine = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	customContext.file = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	montyFile = fopen(argv[1], "r");
	customContext.file = montyFile;

	if (!montyFile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readLine > 0)
	{
		lineContent = NULL;
		readLine = getline(&lineContent, &size, montyFile);
		customContext.lineContent = lineContent;
		count++;

		if (readLine > 0)
		{
			exe_opcode(lineContent, &stack, count, montyFile);
		}

		free(lineContent);
	}
	free_stack(stack);
	fclose(montyFile);
	return (EXIT_SUCCESS);
}

