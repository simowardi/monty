#include "monty.h"

/**
 * my_add_node - Adds a new node to the head of the stack.
 * @head: Pointer to the head of the stack
 * @n: Value to be stored in the new node
 * Return: No return value
 */
void my_add_node(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (aux != NULL)
		aux->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

