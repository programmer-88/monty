#include "monty.h"

/**
 * add - adds the 2 top elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current;


	if (len_stack(*stack) < 2)
		op_err(5, *stack, g_info.opcode, line_number);

	current = *stack;

	*stack = current->next;
	(*stack)->n = (*stack)->n + current->n;
	(*stack)->prev = NULL;
	free(current);
}


/**
 * nop - does not do anything
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the two top elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current;


	if (len_stack(*stack) < 2)
		op_err(5, *stack, g_info.opcode, line_number);

	current = *stack;

	*stack = current->next;
	(*stack)->n = (*stack)->n - current->n;
	(*stack)->prev = NULL;
	free(current);
}

/**
 * div - divides the 2 top elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void div(stack_t **stack, unsigned int line_number)
{
	stack_t *current;


	if (len_stack(*stack) < 2)
		op_error(5, *stack, g_info.opcode, line_number);

	current = *stack;

	*stack = current->next;
	if (current->n == 0)
		op_error_fail(7, *stack, g_info.opcode, line_number);
	(*stack)->n = (*stack)->n / current->n;
	(*stack)->prev = NULL;
	free(current);
}

/**
 * mul - multiplies the 2 top values of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current;


	if (len_stack(*stack) < 2)
		op_err(5, *stack, g_info.opcode, line_number);

	current = *stack;

	*stack = current->next;
	(*stack)->n = (*stack)->n * current->n;
	(*stack)->prev = NULL;
	free(current);
}
