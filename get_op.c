#include "monty.h"
/**
 * get_op - gets the operation function
 * @s: Argument passed as operator
 * @head: head of the stack
 * @line_num: Line Number
 * Return: Return the Operation
 */
void get_op(stack_t **head, char *ction, unsigned int line_num)
{
	int i;
	instruction_t fun[] = OPCODES;

	if (ction == NULL)
		return;
	for (i = 0; fun[i].opcode; i++)
	{
		if (strcmp(fun[i].opcode, ction) == 0)
		{
			fun[i].f(head, line_num);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, ction);
	ag = "error";
}
