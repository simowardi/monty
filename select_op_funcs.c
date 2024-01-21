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
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
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

