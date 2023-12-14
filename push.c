#include "monty.h"
/**
 * implement_push - for adding node to the stack
 * @head: indicates stack head
 * @counter: line_number
 * Return: nothing
*/
void implement_push(stack_t **head, unsigned int counter)
{
	int num, j = 0, flags = 0;

	if (dis.arg)
	{
		if (dis.arg[0] == '-')
			j++;
		for (; dis.arg[j] != '\0'; j++)
		{
			if (dis.arg[j] > 57 || dis.arg[j] < 48)
				flags = 1; }
		if (flags == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(dis.file);
			free(dis.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(dis.file);
		free(dis.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	num = atoi(dis.arg);
	if (dis.change == 0)
		addnode(head, num);
	else
		addqueue(head, num);
}
