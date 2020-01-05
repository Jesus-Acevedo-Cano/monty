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

	new->n = atoi(globalV);
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
/*__________________________________________________*/
