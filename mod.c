#include "monty.h"

/**
 * m_mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void m_mod(stacky_t **head, unsigned int counter)
{
	stacky_t *current;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(dis.file);
		free(dis.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;

	if (current->num == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(dis.file);
		free(dis.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	*head = current->next;
	(*head)->num %= current->num;

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
