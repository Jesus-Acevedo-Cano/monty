#include "monty.h"

/**
 * push_int - function to add a new node at end
 * @head: Pointer to head of list
 * @n: node value
 * Return: list
 */

void push_int(stack_t **head, unsigned int n)
{
	stack_t *new, *tmp = *head;

	if (head == NULL)
		return;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return;

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*head == NULL)
	{
		*head = new;
		return;
	}
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			new->prev = tmp;
			return;
		}
		tmp = tmp->next;
	}
	exit(EXIT_SUCCESS);
}
/**
 *pall_int - print values on stack
 *@stack: Double pointer
 *@line_number: Line number
 */

void pall_int(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
