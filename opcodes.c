#include "monty.h"
/**
 * op_pall - prints the entire stack
 * @head: The head of the stack
 * @i: unused indexer
 */
void op_pall(stack_t **head, __attribute__((unused))unsigned int i)
{
	stack_t *tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * op_pint - prints an integer
 * @head: head of the stack
 * @i: Line number integer
 */
void op_pint(stack_t **head, unsigned int i)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", i);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * op_pop - displays the stack
 * @head: The head of the stack
 * @i: Line number
 */
void op_pop(stack_t **head, unsigned int i)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", i);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * op_swap - Swaps two stack elements
 * @head: the head of the stack
 * @i: Line number
 */
void op_swap(stack_t **head, unsigned int i)
{
	stack_t *tmp;
	int swap;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", i);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	swap = (*head)->n;
	(*head)->n = tmp->n;
	tmp->n = swap;
}

/**
 * op_add - adds two stack elements
 * @head: The head of the stack
 * @i: Line number
 */
void op_add(stack_t **head, unsigned int i)
{
	int a, b, sum;
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", i);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", i);
		exit(EXIT_FAILURE);
	}

	a = (*head)->n;
	b = tmp->n;
	sum = a + b;

	tmp->n = sum;
	tmp->prev = NULL;
	free(*head);
	*head = tmp;
}
