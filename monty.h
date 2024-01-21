#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* @args: op file parse/tokenized arguments of lines */
extern char *args[];

#define DELIM " \n\t\a\r;:"

char *args[3];

/* add to stack and free stack function*/
stack_t *stack_addnode(stack_t **head, const int n);
void node_free(stack_t *head);

/*token / parser function*/
void token_args(char *opcode_line);

/* op select function */
void (*select_op_code(void))(stack_t **headstack, unsigned int number_line);

/* opfunction */
void monty_push(stack_t **headstack, unsigned int number_line);
void monty_pall(stack_t **headstack, unsigned int number_line);
void monty_pint(stack_t **headstack, unsigned int number_line);
void monty_pop(stack_t **headstack, unsigned int number_line);
void monty_swap(stack_t **headstack, unsigned int number_line);
void monty_add(stack_t **headstack, unsigned int number_line);
void monty_nop(stack_t **headstack, unsigned int number_line);

#endif

