#include "monty.h"

/**
 * monty_swap - a function that swaps the top two elements of the stack
 * @headstack: a pointer tath poit to the head node of stack
 * @number_line: line number in the Monty bytecode file.
 * Return: Nothing
 */
void monty_swap(stack_t **headstack, unsigned int number_line)
{
	stack_t *temp, *p;

	if (*headstack == NULL || (*headstack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", number_line);
		exit(EXIT_FAILURE);
	}
	temp = *headstack;
	p = (*headstack)->next;
	if (p->next == NULL)
	{
		temp->next = NULL;
		temp->prev = p;
		p->prev = NULL;
		p->next = temp;
		*headstack = p;
	}
	else
	{
		temp->next = p->next;
		temp->prev = p;
		p->prev = NULL;
		p->next = temp;
		*headstack = p;
	}
}

/**
 * monty_add - a function that that adds the top two elements of the stack
 * @headstack: a pointer to the head node of stack
 * @number_line: a line number in the Monty bytecode file.
 * Return: Nothing
 */
void monty_add(stack_t **headstack, unsigned int number_line)
{
	/* check if stack contains at least two elements */
	if (*headstack == NULL || (*headstack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", number_line);
		exit(EXIT_FAILURE);
	}

	(*headstack)->next->n += (*headstack)->n;
	pop(headstack, number_line);
}

/**
 * monty_nop - a function that Do nothing
 * @headstack: a pointer to the head node of stack
 * @number_line: a line number in the Monty bytecode file.
 * Return: Nothing
 */
void monty_nop(stack_t **headstack, unsigned int number_line)
{
	(void)headstack;
	(void)number_line;
}

