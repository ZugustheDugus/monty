#include "monty.h"
/**
 * op_pall - prints the entire stack
 * @head: The head of the stack
 * @i: unused indexer
 */
void op_pall(stack_t **head, __attribute__((unused))unsigned int i)
{
	stack_t *tmp;

	if (head)
	{
		tmp = *head;
		while (tmp)
		{
			printf("%d/n", tmp->n);
			tmp = tmp->prev;
		}
	}
}

/**
 * op_pint - prints an integer
 * @head: head of the stack
 * @i: Line number integer
 */
void op_pint(stack_t **head, unsigned int i)
{
	stack_t *tmp;

	tmp = *head;
	if (tmp)
	{
		printf("%d\n", tmp->n);
		return;
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", i);
		arg = "error";
		return;
	}
}

/**
 * op_pop - displays the stack
 * @head: The head of the stack
 * @i: Line number
 */
void op_pop(stack_t **head, unsigned int i)
{
	stack_t *tmp = NULL;

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", i);
		arg = "error";
		return;
	}
	tmp = (*head)->prev;
	free(*head);
	*head = tmp;
	if (!*head)
		return;
	(*head)->next = NULL;
return;
}

/**
 * op_swap - Swaps two stack elements
 * @head: the head of the stack
 * @i: Line number
 */
void op_swap(stack_t **head, unsigned int i)
{
	stack_t *tmp;
	int swap, y;

	if (!*head)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", i);
		arg = "error";
		return;
	}
	tmp = *head;
	swap = tmp->n;
	tmp = tmp->prev;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", i);
		arg = "error";
		return;
	}

	y = tmp->n;
	tmp->n = swap;
	tmp = tmp->next;
	tmp->n = y;
return;
}

/**
 * op_add - adds two stack elements
 * @head: The head of the stack
 * @i: Line number
 */
void op_add(stack_t **head, unsigned int i)
{
	int a, b;
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", i);
		arg = "error";
		return;
	}
	tmp = *head;
	a = tmp->n;
	tmp = tmp->prev;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", i);
		arg = "error";
		return;
	}

	b = tmp->n;
	tmp->n = (a + b);
	*head = tmp;
	tmp = tmp->next;
	free(tmp);
return;
}
