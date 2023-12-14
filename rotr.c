#include "monty.h"

/**
 * r_rotr - used to rotate the stack to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void r_rotr(stacky_t **head, __attribute__((unused)) unsigned int counter)
{
	stacky_t *copy;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	copy = *head;
	while (copy->next)
	{
		copy = copy->next;
	}

	copy->previous->next = NULL;
	copy->previous = NULL;
	copy->next = *head;
	(*head)->previous = copy;
	(*head) = copy;
}
