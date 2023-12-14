#include "monty.h"

/**
 * p_pstr - prints the string starting at the top of the stack
 * @head: stack head
 * @counter: line number
 */
void p_pstr(stacky_t **head, unsigned int counter)
{
	stacky_t *current = *head;

	while (current != NULL && current->num != 0 && isascii(current->num))
	{
		putchar(current->num);
		current = current->next;
	}
	putchar('\n');
	(void)counter;
}
