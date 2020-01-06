#include "monty.h"
global globalVar = {NULL, NULL, NULL, 0};

/**
 * main - Main function
 * @argc: Number of arguments.
 * @argv: Arguments
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *fileN = argv[1];

	if (argc == 2)
	{
		op_file(fileN);
		free_n();
	}
	else
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
	return (0);
}

/**
 * free_n - Frees function
 */

void free_n(void)
{
	stack_t *tmp;

	if (globalVar.head == NULL)
		return;

	while (globalVar.head != NULL)
	{
		tmp = globalVar.head;
		globalVar.head = globalVar.head->next;
		free(tmp);
	}
}

/**
 *
 *
 */

void freeAll(void)
{
	if (globalVar.fp != NULL)
		fclose(globalVar.fp);
	if (globalVar.line != NULL)
		free(globalVar.line);
	free_n();
}
