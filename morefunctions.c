#include "monty.h"

/**
 * mul_int - multiplicates the top two elements
 * @stack: double pointer to top node
 * @line_number: line number
 */

void mul_int(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", line_number);
		freeAll();
		exit(EXIT_FAILURE);
	}
	new = (*stack)->next;
	(*stack)->next->n *= (*stack)->n;
	free(*stack);
	new->prev = NULL;
	(*stack) = new;
}
