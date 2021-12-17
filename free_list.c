#include "monty.h"

/**
 * free_list - Frees the list
 * @s: Head of the list
 * Return: 0 on success, else 1
 *
 */

void free_list(stack_t *s)
{
	stack_t *i = s;

	if (s == NULL)
		return;
	while (i)
	{
		s = s->next;
		free(i);
		i = s;
	}
	s = NULL;
}
