#include "monty.h"

/**
 * addnode - Add a new node to the head of the stack
 * @head: Pointer to the head of the stack
 * @n: Value to be stored in the new node
 * Return: No return value
 */
void addnode(stacky_t **head, int n)
{
	stacky_t *new_node;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(stacky_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new_node->num = n;
	new_node->previous = NULL;

	/* Link the new node to the current head, if it exists */
	if (*head != NULL)
	{
		new_node->next = *head;
		(*head)->previous = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	/* Update the head to point to the new node */
	*head = new_node;
}
