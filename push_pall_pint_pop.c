#include "monty.h"

/**
 * push_monty - Adds a node to the stack or queue.
 * @stack: A Pointer to the stack
 * @line_number: the Line number in the script
 * Return: No return Value .
 */
void push_monty(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (montyContext.argument)
	{
		if (montyContext.argument[0] == '-')
			j++;

		while (montyContext.argument[j] != '\0')
		{
			if (!isdigit(montyContext.argument[j]))
				flag = 1;
			j++;
		}

		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(montyContext.file);
			free(montyContext.lineContent);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(montyContext.file);
		free(montyContext.lineContent);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(montyContext.argument);

	if (montyContext.flagLifi == 0)
		add_node(stack, n);
	else
		add_queue(stack, n);
}

/**
 * pall_monty - Prints all values on the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number in the script (not used)
 * Return: No return value
 */
void pall_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint_monty - Prints the top element of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number in the script
 * Return: No return value
 */
void pint_monty(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(montyContext.file);
		free(montyContext.lineContent);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_monty - Removes the top element of the stack.
 * @stack: Pointer to the stack
 * @line_number: Line number in the script
 * Return: No return value
 */
void pop_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(montyContext.file);
		free(montyContext.lineContent);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = current->next;
	free(current);
}

