#include "monty.h"
/**
 * main - main interpreter body
 * @argc: Count of Arguments
 * @argv: Arguments
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	FILE *file;
	char str[1024], **op;
	unsigned int i = 1;
	void (*op_func)(stack_t **, unsigned int);
	stack_t **head = malloc(sizeof(stack_t));

	if (!head)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	if (argc != 2)
		free(head), fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		free(head), fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	*head = NULL;
	while (fgets(str, sizeof(str), file) != NULL)
	{
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = '\0';
		op = tokenize(str);
		if (op[0] == NULL)
		{
			free(op);
			continue;
		}
		else if (strcmp(op[0], "nop") == 0)
		{
			free(op);
			continue;
		}
		else if (strcmp(op[0], "push") == 0)
		{
			if (op[1] != NULL)
				op_push(head, op[1], i);
			else
			{
				if (head != NULL)
					free_list(head), free(head);
				else
					free(head);
				fclose(file), free(op);
				fprintf(stderr, "L%d: usage: push integer\n", i);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			op_func = get_op(op[0]);
			if (op_func != NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", i, op[0]);
				fclose(file), free_list(head), free(head), free(op);
				exit(EXIT_FAILURE);
			}
		}
		free(op), i++;
	}
	free_list(head); free(head), fclose(file);
	return (0);
}
