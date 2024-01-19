#include "monty.h"
/**
 * swap_top_two_elements - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number in the script
 * Return: No return value
 */
void swap_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int length = 0, temp;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(montyContext.file);
		free(montyContext.lineContent);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}

/**
  *nop_nothing - The opcode nop doesn’t do anything.
  *@head: the stack head
  *@line_num: the line number
  *Return: no return
 */
void nop_nothing(stack_t **head, unsigned int line_num)
{
	(void) line_num;
	(void) head;
}

/**
 * add_top_two_elements - Adds the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number in the script
 * Return: No return value
 */
void add_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int length = 0, result;

	while (current)
	{
		current = current->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(montyContext.file);
		free(montyContext.lineContent);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	result = current->n + current->next->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}

