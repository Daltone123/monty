#include "monty.h"
/**
 * p_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: nothing
*/
void p_pint(stack_t **head, unsigned int counter)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(dis.file);
		free(dis.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->num);
}
