#include "monty.h"

/**
 * op_file - Function to open file
 * @fileN: Name of file
 * Return: Always 0
 */

int op_file(char *fileN)
{
	char *tokcmd, *tokarg;
	size_t len = 0;
	ssize_t read;

	globalVar.fp = fopen(fileN, "r");
	if (globalVar.fp == NULL)
	{
		dprintf(STDERR_FILENO, "imp error cant open file");
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&(globalVar.line), &len, globalVar.fp)) != -1)
	{
		globalVar.line_number++;
		tokcmd = strtok(globalVar.line, "\n\t ");
		tokarg = strtok(NULL, "\n\t ");
		exect(tokcmd, tokarg, &(globalVar.head));
	}
	freeAll();
	exit(EXIT_SUCCESS);
}

/**
 * exect - function to exect commands
 * @cmd: command argument
 * @arg: arguments
 * Return: Always 0
 */

int exect(char *cmd, char *arg, stack_t **head)
{
	if (arg != NULL)
		(get_function(cmd))(head, atoi(arg));
	else
		(get_function(cmd))(head, 0);

	return (0);
}

/**
 * get_function - Short desc
 * @opcode: opcode
 * Return: void
 */

void (*get_function(char *opcode))(stack_t **stack, unsigned int line_number)
{
	char *msg = ": unknown instruction ";
	int cnt = 0;
	instruction_t opcode_fn[] = {
		{"pall", pall_int},
		{"push", push_int},
		{NULL, NULL}
	};
	/**if (opcode[0] == '#')
	   return;*/

	for (cnt = 0; opcode_fn[cnt].opcode != NULL; cnt++)
	{
		if (!opcode)
			return NULL;
		if (strcmp(opcode, opcode_fn[cnt].opcode) == 0)
		{
			return (opcode_fn[cnt].f);
		}
	}
	dprintf(STDERR_FILENO, "L%u%s%s\n", globalVar.line_number, msg, opcode);
	freeAll();
	exit(EXIT_FAILURE);
}
