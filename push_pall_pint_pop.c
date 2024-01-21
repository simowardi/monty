#include "monty.h"

/**
 * monty_push - function that Pushes a value to a stack_t linked list.
 * @headstack: pointer to head node of stack
 * @number_line: line number in the Monty bytecode file.
 * Return: Nothing
 */
void monty_push(stack_t **headstack, unsigned int number_line)
{
	int j;

	if (args[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", number_line);
		node_free(*headstack);
		exit(EXIT_FAILURE);
	}
	if (strcmp(args[1], "-0") == 0)
		args[1] = "0";
	if (strcmp(args[1], "0") != 0 && atoi(args[1]) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", number_line);
		node_free(*headstack);
		exit(EXIT_FAILURE);
	}
	if (args[1][0] == '-')
		j = 1;
	else
		j = 0;
	while (args[1][j] != '\0') /*identify non-integer element*/
	{
		if (!isdigit(args[1][j]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", number_line);
			node_free(*headstack);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	if (stack_addnode(headstack, atoi(args[1])) == NULL)
	{
		node_free(*headstack);
		exit(EXIT_FAILURE);
	}
}

/**
 * monty_pall - a function that print stack elements
 * @headstack: a pointer to head node of stack
 * @number_line: a line number in the Monty bytecode file.
 * Return: Nothing
 */
void monty_pall(stack_t **headstack, unsigned int number_line)
{
	stack_t *p;

	(void)number_line;
	if (headstack != NULL || *headstack != NULL)
	{
		p = *headstack;
		while (p)
		{
			printf("%d\n", p->n);
			p = p->next;
		}
	}
}

/**
 * monty_pint - prints the value at the top of the stack
 * @headstack: a pointer to the head node of stack
 * @number_line: a line number in the Monty bytecode file.
 * Return: Nothing
 */
void monty_pint(stack_t **headstack, unsigned int number_line)
{
	if (headstack == NULL || *headstack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", number_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*headstack)->n);
}

/**
 * monty_pop - removes the top element of the stack
 * @headstack: a pointer to the head node of stack
 * @number_line: a line number in the Monty bytecode file.
 * Return: Nothing
 */
void monty_pop(stack_t **headstack, unsigned int number_line)
{
	stack_t *p;

	if (headstack == NULL || *headstack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", number_line);
		exit(EXIT_FAILURE);
	}
	p = *headstack;
	if ((*headstack)->next == NULL)
	{
		*headstack = NULL;
		free(p);
	}
	else
	{
		*headstack = (*headstack)->next;
		(*headstack)->prev = NULL;
		free(p);
	}
}

