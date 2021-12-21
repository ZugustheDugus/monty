#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
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
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

#define OPCODES {\
	{"pall", op_pall},\
	{"pint", op_pint},\
	{"pop", op_pop},\
	{"swap", op_swap},\
	{"add", op_add},\
	{"push", push},\
	{"nop", nop},\
	{NULL, NULL},\
}

extern char *ag;
char *ag;

void free_list(stack_t **head);
void get_op(stack_t **head, char *fun, unsigned int lc);
void op_pall(stack_t **head, __attribute__((unused))unsigned int i);
void op_pint(stack_t **head, unsigned int i);
void op_pop(stack_t **head, unsigned int i);
void op_swap(stack_t **head, unsigned int i);
void op_add(stack_t **head, unsigned int i);
void op_push(stack_t **head, char *str, unsigned int i);
void nop(stack_t **stack, unsigned int lc);
void push(stack_t **stack, unsigned int lc);
char **tokenize(char *str);

#endif
