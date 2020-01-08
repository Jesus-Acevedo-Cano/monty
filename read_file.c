#include "monty.h"

/**
 * op_file - Function to open file
 * @fileN: Name of file
 * Return: Always 0
 */

int op_file(char *fileN)
{
	char *tokcmd;
	size_t len = 0;
	ssize_t read;

	globalVar.fp = fopen(fileN, "r");
	if (globalVar.fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", fileN);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&(globalVar.line), &len, globalVar.fp)) != -1)
	{
		globalVar.line_number++;
		tokcmd = strtok(globalVar.line, "\n\t ");
		if (tokcmd != NULL && tokcmd[0] != '#')
		{
			globalVar.nValue = strtok(NULL, "\n\t ");
			exect(tokcmd, globalVar.nValue, &(globalVar.head));
		}
	}
	freeAll();
	exit(EXIT_SUCCESS);
}

/**
 * exect - function to exect commands
 * @cmd: command argument
 * @arg: arguments
 * @head: head
 * Return: Always 0
 */

int exect(char *cmd, char *arg, stack_t **head)
{
	(void) arg;
	(get_function(cmd))(head, globalVar.line_number);

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
		{"pint", pint_int},
		{"nop", nop_int},
		{"pop", pop_int},
		{"swap", swap_int},
		{"add", add_int},
		{"sub", sub_int},
		{"div", div_int},
		{"mul", mul_int},
		{NULL, NULL}
	};

	for (cnt = 0; opcode_fn[cnt].opcode != NULL; cnt++)
	{
		if (!opcode)
			return (NULL);
		if (strcmp(opcode, opcode_fn[cnt].opcode) == 0)
		{
			return (opcode_fn[cnt].f);
		}
	}
	dprintf(STDERR_FILENO, "L%u%s%s\n", globalVar.line_number, msg, opcode);
	freeAll();
	exit(EXIT_FAILURE);
}

/**
 * add_int - Adds the top two elements
 * @stack: double pointer to top node
 * @line_number: line number
 */

void add_int(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	new = (*stack)->next;
	(*stack)->next->n += (*stack)->n;
	free(*stack);
	new->prev = NULL;
	(*stack) = new;
}

/**
 * sub_int - substract the top two elements
 * @stack: double pointer to top node
 * @line_number: line number
 */

void sub_int(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	new = (*stack)->next;
	(*stack)->next->n -= (*stack)->n;
	free(*stack);
	new->prev = NULL;
	(*stack) = new;
}
