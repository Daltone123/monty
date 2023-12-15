#include "monty.h"
/**
 * implement_pall - for printing the stack the stack in question
 * @head: the stack head
 * @counter: has not been used
 * Return: nothing
*/
void implement_pall(stacky_t **head, unsigned int counter)
{
	stacky_t *current;
	(void)counter;

	current = *head;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->num);
		current = current->next;
	}
}
