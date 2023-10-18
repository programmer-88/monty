#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>

/**
 * struct global_info_s - global variables
 * @file: Pointer to the file
 * @line: Pointer to the current line
 * @opcode: the opcode
 * @arg: the opcode argument
 */
typedef struct global_info_s
{
	FILE *file;
	char *line;
	char *opcode;
	char *arg;
	int lifo;
} global_info;
extern global_info g_info;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* HELPERS */
void exec_interpr(stack_t **stack);
void all_free(stack_t *head);
void ln_parser(void);
void (*op_func_get(char *opcode))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
int is_number(char *str);
stack_t *add_nodeint_end(stack_t **h, const int n);
void free_stack(stack_t *head);
int stack_len(stack_t *head);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);
stack_t *add_node_queue(stack_t **h, const int n);

/*   Error functions  */
void global_error(int error_code, ...);
void op_error(int error_code, ...);
void op_error_bis(int error_code, ...);
#endif
