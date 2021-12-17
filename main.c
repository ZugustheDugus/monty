#include "monty.h"

global_var global_variable;

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Description: Runs monty files
 * Return: 0
 */

int main(int argc, char **argv)
{
	char l[80], *t, array[2][80];
	int y = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global_variable.file = fopen(argv[1], "r");

	if (!(global_variable.file))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	global_variable.line_number = 1;
	global_variable.stack = NULL;
	global_variable.queue_ask = 0;
	while (fgets(l, sizeof(l), global_variable.file))
	{
		y = 0;
		memset(array[0], 0, 80);
		memset(array[1], 0, 80);
		t = strtok(l, " \n\t");
		if (t)
		{
			while (t != NULL)
			{
				strcpy(array[y], t);
				t = strtok(NULL, " \n\t");
				y++;
			}
			execOp(array);
		}
		global_variable.line_number++;
	}
	fclose(global_variable.file);
//	free_list(global_variable.stack);
	return (0);
}
