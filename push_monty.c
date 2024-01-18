#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @stack: Pointer to the stack
 * @line_number: Current line number in the script
 * @data: The data to push onto the stack
 */
void push(stack_t **stack, unsigned int line_number, char *data)
{
	if (data == NULL || !is_numeric(data))
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}

	int num = atoi(data);

	if (num == 0 && data[0] != '0')  /*Check if atoi failed*/

	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Create a new node and add it to the stack */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * is_numeric - Checks if a string is a valid numeric representation
 *
 *@str: Pointer to the null-terminated string to be checked
 * Returns: 1 if the string is a valid numeric , 0 otherwise.
 *
**/
int is_numeric(const char *str)
{
	if (str == NULL || *str == '\0' || *str == '\n')
		return (0);

	int i = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}

	for (; str[i] != '\0' && str[i] != '\n'; i++)
	{
		if (!isdigit((unsigned char)str[i]))
		{
			return (0);
		}
	}

	return (1);
}

