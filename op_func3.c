#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: an pointer to the first node of the stack
 * @line_number: The line number
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	g_info.lifo = 1;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: an pointer to the first node of the stack
 * @line_number: the line number
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	g_info.lifo = 0;
}
