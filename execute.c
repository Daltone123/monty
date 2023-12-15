#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * Return: no return
 */
int execute(char *content, stacky_t **stack, unsigned int counter, FILE *file)
{
	instruct_t opst[] = {
		{"push", implement_push}, {"pall", implement_pall}, {"pint", p_pint},
		{"pop", f_pop},
		{"swap", s_swap},
		{"add", a_add},
		{"nop", n_nop},
		{"sub", s_sub},
		{"div", d_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", p_pchar},
		{"pstr", p_pstr},
		{"rotl", r_rotl},
		{"rotr", r_rotr},
		{"queue", s_queue},
		{"stack", s_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	dis.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].fa(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
