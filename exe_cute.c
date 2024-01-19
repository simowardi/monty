#include "monty.h"

/**
 * exe_opcode - executes the opcode
 * @stack_h: head linked list - stack
 * @count: line_counter
 * @file: a pointer to monty file
 * @ct: the line content
 * Return: no return
 */
int exe_opcode(char *ct, stack_t **stack_h, unsigned int count, FILE *file)
{
	unsigned int i = 0;
	char *op;

	instruction_t opst[] = {
	{"push", push_monty}, {"pall", pall_monty}, {"pint", pint_monty},
	{"pop", pop_monty}, {"swap", swap_top_two_elements}, {"nop", nop_nothing},
	{"add", add_top_two_elements}, /* all my opcode */
	{NULL, NULL}
	};

	op = strtok(ct, " \n\t");
	if (op && op[0] == '#')
		return (0);

	montyContext.argument = strtok(NULL, " \n\t");

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack_h, count);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(ct);
		free_stack(*stack_h);
		exit(EXIT_FAILURE);
	}

	return (1);
}

