#include "monty.h"

/**
 * push_int - function to add a new node at end
 * @head: Pointer to head of list
 * @n: node value
 * Return: list
 */

void push_int(stack_t **head, unsigned int n)
{
	stack_t *new = *head;
	char *msg = ": usage: push integer\n";
	int i = 0;
	(void) n;

	if (globalVar.nValue == NULL)
	{
		dprintf(STDERR_FILENO, "L%u%s", globalVar.line_number, msg);
		freeAll();
		exit(EXIT_FAILURE);
	}
	if (globalVar.nValue[0] == '-')
		i = 1;
	for (; globalVar.nValue[i] != '\0'; i++)
	{
		if (isdigit(globalVar.nValue[i]) == 0)
		{
			dprintf(STDERR_FILENO, "L%u%s", globalVar.line_number, msg);
			freeAll();
			exit(EXIT_FAILURE);
		}
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		freeAll();
		exit(EXIT_FAILURE);
	}
	new->n = atoi(globalVar.nValue);
	new->next = NULL;
	new->prev = NULL;
	if (*head == NULL)
	{
		*head = new;
		return;
	}
	new->next = *head;
	(*head)->prev = new;
	*head = new;
}

/**
 *pall_int - print values on stack
 *@stack: Double pointer
 *@line_number: Line number
 */

void pall_int(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	(void) line_number;

	while (new)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

/**
 *pint_int - print top value
 *@stack: Double pointer
 *@line_number: Line number
 */

void pint_int(stack_t **stack, unsigned int line_number)
{
	char *msg = "can't pint, stack empty\n";

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: %s", line_number, msg);
		freeAll();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * pop_int - remove top element
 * @stack: double pointer to head
 * @line_number: line number
 *
 * Return: nothing
 */

void pop_int(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	char *msg = "can't pop an empty stack\n";

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: %s", line_number, msg);
		freeAll();
		exit(EXIT_FAILURE);
	}

	new = new->next;
	free(*stack);
	*stack = new;

}

/**
 * swap_int - swaps the two top elements
 * @stack: double pointer to head
 * @line_number: line number
 *
 * Return: void
 */

void swap_int(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	int val;

	if (new == NULL || new->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}

	new = new->next;
	val = new->n;
	new->n = (*stack)->n;
	(*stack)->n = val;

}
