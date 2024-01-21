#include "monty.h"

/**
 * select_op_code - Selects the function for the given opcode
 * @void - no argument
 * Return: Nothing
 */
void (*select_op_code(void))(stack_t **headstack, unsigned int line_num)
{
	unsigned int j = 0;

	instruction_t custom_operations[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{"nop", nop},
		{NULL, NULL}
	};
	while (custom_operations[j].opcode != NULL)
	{
		if (strcmp(args[0], custom_operations[j].opcode) == 0)
			return (custom_operations[j].f);
		j++;
	}
	return (NULL);
}

