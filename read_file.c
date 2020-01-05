#include "monty.h"

/**
 * op_file - Function to open file
 * @fileN: Name of file
 * Return: Always 0
 */

int op_file(char *fileN)
{
	FILE *fp = NULL;
	char *line = NULL, *tokcmd, *tokarg;
	size_t len = 0;
	ssize_t read;

	fp = fopen(fileN, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		tokcmd = strtok(line, " ");
		tokarg = strtok(NULL, " ");
		exect(tokcmd, tokarg);
	}

	free(line);
	exit(EXIT_SUCCESS);
}

/**
 * exect - function to exect commands
 * @cmd: command argument
 * @arg: arguments
 * Return: Always 0
 */

int exect(char *cmd, char *arg)
{
	char *globalV = arg;
	stack_t *head = NULL;

	printf("%s %s", cmd, arg);
	(get_function(cmd))(&head, 0);
	printf("%d", head->n);
}

/**
 * get_function - Short desc
 * @opcode: opcode
 * Return: void
 */

void (*get_function(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int cnt = 0;
	instruction_t opcode_fn[] = {
		{"push", push_int},
		{NULL, NULL}
	};

	for (cnt = 0; opcode_fn[cnt].opcode != NULL; cnt++)
	{
		if (strcmp(opcode, opcode_fn[cnt].opcode) == 0)
			return (opcode_fn[cnt].f);
	}
	return (NULL);
}
