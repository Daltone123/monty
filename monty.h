#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct stacky_s
{
	int num;
	struct stacky_s *previous;
	struct stacky_s *next;
} stacky_t;

/**
 * struct stacky_s - this is a doubly linked
 * list representation of a stack (or queue)
 * @num: integer
 * @previous: it is pointing to the previous element of the stack (or queue)
 * @next: it i pointing to the next element of the stack (or queue)
 *
 * Description: this is a modified doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct dis_s
{
	char *arg;
	FILE *file;
	char *content;
	int change;
}  dis_t;
extern dis_t dis;
/**
 * struct dis_s - indicates the variables -arguments, files, and line content
 * @arg: indicate the value
 * @file:a pointer to my monty file
 * @content: line content
 * @change: for changing the flag stack <-> queue
 * Description: used to carry values through the program
 */
typedef struct instruct_s
{
	char *opcode;
	void (*fa)(stacky_t **stack, unsigned int line_number);
} instruct_t;

/**
 * struct instruct_s - this is an opcode and all its function
 * @opcode: the modified opcode
 * @fa: function to handle the opcode
 *
 * Description: the opcode and its function used
 * for stack, queues, LIFO, FIFO Holberton project
 */

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void implement_push(stacky_t **head, unsigned int number);
void implement_pall(stacky_t **head, unsigned int number);
void p_pint(stacky_t **head, unsigned int number);
int execute(char *content, stacky_t **head, unsigned int counter, FILE *file);
void free_stack(stacky_t *head);
void f_pop(stacky_t **head, unsigned int counter);
void s_swap(stacky_t **head, unsigned int counter);
void a_add(stacky_t **head, unsigned int counter);
void n_nop(stacky_t **head, unsigned int counter);
void s_sub(stacky_t **head, unsigned int counter);
void d_div(stacky_t **head, unsigned int counter);
void m_mul(stacky_t **head, unsigned int counter);
void m_mod(stacky_t **head, unsigned int counter);
void p_pchar(stacky_t **head, unsigned int counter);
void p_pstr(stacky_t **head, unsigned int counter);
void r_rotl(stacky_t **head, unsigned int counter);
void r_rotr(stacky_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stacky_t **head, int n);
void addqueue(stacky_t **head, int n);
void s_queue(stacky_t **head, unsigned int counter);
void s_stack(stacky_t **head, unsigned int counter);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int isascii(int c);
#endif
