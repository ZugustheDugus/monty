#include "monty.h"
/**
 * op_push - Pushes a new element to stack
 * @head: The head of the stack
 * @str: The string pushed to stack
 * @i: Value given
 */
void op_push(stack_t **head, unsigned int i)
{
	stack_t *newn = malloc(sizeof(stack_t));
	int x = atoi(arg);

	if (!newn)
	{
		free(newn);
		fprintf(stderr, "Error: malloc failed\n");
		arg = "error";
		return;
	}
	while (*arg)
	{
		if (*arg == '-')
			arg++;
		if (isdigit(*arg) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", i);
			arg = "error";
			free(newn);
			return;
		}
		arg++;
	}
	newn->n = x;
	newn->next = NULL;
	newn->prev = *head;
	if (*head)
		(*head)->next = newn;
	*head = newn;
	return;
}
