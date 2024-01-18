#include "monty.h"
#include <stdio.h>

/**
 * pall - Prints all values on the stack
 * @stack: Pointer to the stack
 * @line_number: Current line number in the script
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
		return;  /* Nothing to print */

	/* Print all values on the stack */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

