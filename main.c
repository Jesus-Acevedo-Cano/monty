#include "monty.h"
global globalVar = {NULL, NULL, NULL, 0, NULL};

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
		freeAll();
	}
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
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
 * freeAll - free all
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

/**
 * nop_int - do nothing
 * @stack: stack
 * @line_number: line number
 *
 * Return: nothing
 */

void nop_int(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * div_int - divides the top two elements
 * @stack: double pointer to top node
 * @line_number: line number
 */

void div_int(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;
	(*stack)->next->n /= (*stack)->n;
	free(*stack);
	new->prev = NULL;
	(*stack) = new;
}
