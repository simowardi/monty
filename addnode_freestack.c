#include "monty.h"

/**
 * stack_addnode - in  beginning of stack_t list adds a new node.
 * @headstack: a pointer to the head of the list of node.
 * @nvalue: the value of naw noode
 * Return: address of the new element, or NULL if it failed
 */
stack_t *stack_addnode(stack_t **headstack, const int nvalue)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (NULL);

	if ((*headstack) == NULL)
	{
		*headstack = newnode;
		newnode->n = nvalue;
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	else
	{
		newnode->n = nvalue;
		newnode->prev = NULL;
		newnode->next = *headstack;
		(*headstack)->prev = newnode;
		*headstack = newnode;
	}
	return (newnode);
}

/**
 * node_free - frees nodes in stack_t list.
 * @headstack: a pointer to head node of list
 * Return: Nothing
 */
void node_free(stack_t *headstack)
{
	stack_t *p;

	if (headstack == NULL)
		return;

	while (headstack)
	{
		p = headstack;
		headstack = headstack->next;
		free(p);
	}
}

