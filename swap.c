#include "monty.h"

/**
 * s_swap - swaps the top two elements of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void s_swap(stacky_t **head, unsigned int counter)
{
	stacky_t *current;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(dis.file);
		free(dis.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	*head = current->next;

	if (current->next != NULL)
	{
		current->previous = *head;
		current->next = (*head)->next;

		if ((*head)->next != NULL)
			(*head)->next->previous = current;
		(*head)->next = current;
		(*head)->previous = NULL;
	}
}
