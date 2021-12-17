#include "monty.h"

/**
 * tokenize - tokenizes a string after splitting it
 * @str: String to tokenize
 * Return: The tokenized array of strings
 */

char **tokenize(char *str)
{
	int i, len = strlen(str);
	char *string = NULL, **hold = NULL;

	hold = malloc(sizeof(char *) * (len * 2));
	string = strtok(str, " \t\r\v");
	for (i = 0; string != NULL; i++)
	{
		hold[i] = string;
		string = strtok(NULL, " ");
	}
	hold[i] = '\0';
	return (hold);
}
