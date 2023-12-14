#include "monty.h"

/**
 * a_sub - subtracts the top element of the stack from the second top element
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void a_sub(stacky_t **head, unsigned int counter)
{
	stacky_t *current;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(dis.file);
		free(dis.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	*head = current->next;
	(*head)->num -= current->num;

	if (current->next != NULL)
	{
		current->previous = *head;
		current->next = (*head)->next;

	if ((*head)->next != NULL)
		(*head)->next->previous = current;

	(*head)->next = current;
	(*head)->previous = NULL;
	}

	free(current);
}
