#include "monty.h"

/**
 * p_pchar - prints the char at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void p_pchar(stacky_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(dis.file);
		free(dis.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->num < 0 || (*head)->num > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(dis.file);
		free(dis.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	putchar((*head)->num);
	putchar('\n');
}
