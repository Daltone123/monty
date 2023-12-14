#include "monty.h"

/**
 * r_rotl - rotates the stack to the top
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number of the opcode
 */
void r_rotl(stacky_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stacky_t *temp, *last;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		last = *stack;

		while (last->next)
			last = last->next;

		*stack = temp->next;
		(*stack)->previous = NULL;
		temp->next = NULL;
		last->next = temp;
		temp->previous = last;
	}
}
