#include "monty.h"

/**
 * main - the monty program main function
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: Always returns 0 on successful execution
 */
int main(int argc, char **argv)
{
	FILE *montyfile;
	char content[200];
	char *args[3];
	unsigned int num_line = 0;
	stack_t *stackHead = NULL; /* empty stack */

	if (argv[1] == NULL || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	montyfile = fopen(argv[1], "r"); /* attempt to open file */
	if (montyfile == NULL) /* validate file */
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(content, sizeof(content), montyfile)) != NULL)
	{
		num_line++;
		if (strlen(content) == 0) /*skip empty lines*/
			continue;
		token_args(content); /*split line argument into variable args */

		if (*args == NULL) /*skip empty lines having delimiters*/
			continue;
		/*for skipping lines with first non-space character #comment*/
		if (strcmp(args[0], "#") == 0 || args[0][0] == '#')
			continue;
		if (select_op_code() == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", num_line, args[0]);
			exit(EXIT_FAILURE);
		}
		else
			select_op_code()(&stackHead, num_line);
	}
	node_free(stackHead);
	fclose(montyfile);
	return (0);
}

