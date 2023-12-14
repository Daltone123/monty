#include "monty.h"

/**
 * s_queue - sets the format of the data to a queue (FIFO)
 * @head: pointer to the head of the stack
 * @counter: line_number
 */
void s_queue(stacky_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	dis.change = 1; /* 1 means queue (FIFO) */
}

/**
 * addqueue - add node to the tail stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void addqueue(stacky_t **head, int n)
{
	stacky_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stacky_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->num = n;
	new_node->next = NULL;

	if (!aux)
	{
		*head = new_node;
		new_node->previous = NULL;
	}
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new_node;
		new_node->previous = aux;
	}
}
