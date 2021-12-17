#include "monty.h"

void push(stack_t **s, unsigned int line_number)
{
	stack_t *top = NULL;

	(void)line_number;
	top = (*s);
	top = malloc(sizeof(s));

	if (top == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}

	top->n = atoi(global_variable.number);
	top->next = *s;
	top->prev = NULL;
	if (*s != NULL)
		(*s)->prev = top;
	*s = top;
}
