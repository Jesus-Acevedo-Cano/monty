#include "monty.h"
stack_t *head = NULL;

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

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
