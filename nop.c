#include "monty.h"

/**
 * p_pop - removes the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void p_pop(stack_t **head, unsigned int counter)
{
	stacky_t *current;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(dis.file);
		free(dis.content);
		exit(EXIT_FAILURE);
	}

	current = (stacky_t *)*head;
	*head = current->next;
	free(current);
}
