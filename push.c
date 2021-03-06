#include "monty.h"
/**
 * push - Adds a new node to the stack
 * @head: Pointer to head
 * @lc: Line count
 */

void push(stack_t **head, unsigned int lc)
{
	stack_t *nnode = malloc(sizeof(stack_t));
	int x = atoi(ag);

	if (!nnode)
	{
		free(nnode);
		fprintf(stderr, "Error: malloc failed\n");
		ag = "error";
		return;
	}
	while (*ag)
	{
		if (*ag == '-')
			ag++;
		if (isdigit(*ag) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lc);
			ag = "error";
			free(nnode);
			return;
		}
		ag++;
	}
	nnode->n = x;
	nnode->next = NULL;
	nnode->prev = *head;
	if (*head)
	{
		(*head)->next = nnode;
	}
	*head = nnode;
	return;
}
