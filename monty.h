#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct MontyContext - Variables - argument, file, lineContent
 * @argument: Value
 * @file: Pointer to Monty file
 * @lineContent: Line content
 * @flagLifi: Flag to change stack <-> queue
 *
 * Description: Carries values through the program
 */
typedef struct MontyContext
{
	char *argument;
	FILE *file;
	char *lineContent;
	int flagLifi;
} MontyContext_t;

extern MontyContext_t montyContext;

int exe_opcode(char *ct, stack_t **stack_h, unsigned int count, FILE *file);
ssize_t getstdin(char **lineptr, int file);

void add_node(stack_t **head, int n);
void free_stack(stack_t *head);

void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int new);


void push_monty(stack_t **head, unsigned int number);
void pall_monty(stack_t **head, unsigned int number);
void pint_monty(stack_t **head, unsigned int number);
void pop_monty(stack_t **head, unsigned int counter);

void swap_top_two_elements(stack_t **stack, unsigned int line_number);
void add_top_two_elements(stack_t **stack, unsigned int line_number);
void nop_nothing(stack_t **head, unsigned int line_num);

#endif
