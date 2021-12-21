#include "monty.h"
/**
 * main - main interpreter body
 * @argc: Count of Arguments
 * @argv: Arguments
 * Return: Exit failure or exit success
 */

int main(int argc, char *argv[])
{
	size_t bsize = 1024;
	char *buff = malloc(bsize * sizeof(char));
	ssize_t ls;
	FILE *f;
	char *comm = NULL;
	stack_t *s = NULL;
	int xstat = EXIT_SUCCESS, lc = 1;

	if (!buff)
	{
		free(buff), fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	f = fopen(argv[1], "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	ls = getline(&buff, &bsize, f);
	while (ls >= 0)
	{
		comm = strtok(buff, " \t\n\r");
		ag = strtok(NULL, " \t\n\r");
		if (ag == NULL)
			ag = "notdigit";
		get_op(&s, comm, lc);
		if (strcmp(ag, "error") == 0)
		{
			xstat = EXIT_FAILURE;
			break;
		}
		ls = getline(&buff, &bsize, f);
		lc++;
	}
	free(buff), free_list(&s), fclose(f), exit(xstat);
}
