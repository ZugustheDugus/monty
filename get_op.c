#include "monty.h"
/**
 * get_op - gets the operation function
 * @s: Argument passed as operator
 * @head: head of the stack
 * @line_num: Line Number
 * Return: Return the Operation
 */
void (*get_op(char *s))(stack_t **head, unsigned int line_num)
{
	instruction_t op_code[] = {
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{NULL, NULL}
	};
	int i = 0;

	while (op_code[i].opcode != NULL && strcmp((op_code[i].opcode), s) != 0)
		i++;
	return (op_code[i].f);
}
