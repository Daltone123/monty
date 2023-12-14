#include "monty.h"

/**
 * a_add - adds the top two elements of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void a_add(stacky_t **head, unsigned int counter)

{
	stacky_t *current;

	if (*head == NULL || (*head)->next == NULL)
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", counter);
	fclose(dis.file);
	free(dis.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
	}
	current = *head;
	*head = current->next;
	(*head)->num += current->num;
	free(current);
}
