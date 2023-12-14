#include "monty.h"
/**
 * implement_pall - for printing the stack the stack in question
 * @head: the stack head
 * @counter: has not been used
 * Return: nothing
*/
void implement_pall(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
