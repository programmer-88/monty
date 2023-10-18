#include "monty.h"

/**
 * _add - adds the two top elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *current;


	if (stack_len(*stack) < 2)
		op_error(5, *stack, g_info.opcode, line_number);

	current = *stack;

	*stack = current->next;
	(*stack)->n = (*stack)->n + current->n;
	(*stack)->prev = NULL;
	free(current);
}


/**
 * _nop - doesn't do anything
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub - subtracts the two top elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current;


	if (stack_len(*stack) < 2)
		op_error(5, *stack, g_info.opcode, line_number);

	current = *stack;

	*stack = current->next;
	(*stack)->n = (*stack)->n - current->n;
	(*stack)->prev = NULL;
	free(current);
}

/**
 * _div - divides the two top elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *current;


	if (stack_len(*stack) < 2)
		op_error(5, *stack, g_info.opcode, line_number);

	current = *stack;

	*stack = current->next;
	if (current->n == 0)
		op_error_bis(7, *stack, g_info.opcode, line_number);
	(*stack)->n = (*stack)->n / current->n;
	(*stack)->prev = NULL;
	free(current);
}

/**
 * _mul - multiplies the two top elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current;


	if (stack_len(*stack) < 2)
		op_error(5, *stack, g_info.opcode, line_number);

	current = *stack;

	*stack = current->next;
	(*stack)->n = (*stack)->n * current->n;
	(*stack)->prev = NULL;
	free(current);
}
