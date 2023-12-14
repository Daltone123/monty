#include "monty.h"

/**
 * m_mul - multiplies the second top element of the stack with the top element
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void m_mul(stacky_t **head, unsigned int counter)
{
	stacky_t *current;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(dis.file);
		free(dis.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	*head = current->next;
	(*head)->num *= current->num;

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
