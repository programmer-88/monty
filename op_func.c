#include "monty.h"

/**
 * push - pushes an integer to stack
 * @stack: The stack
 * @line_number: The line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (!g_info.arg || is_digit(g_info.arg) == 1)
		op_error(2, *stack, g_info.opcode, line_number);

	if (g_info.lifo)
		add_nodeint_end(stack, atoi(g_info.arg));
	else
		add_node_queue(stack, atoi(g_info.arg));
}

/**
 * pall - prints all the values on the stack, starting from
 * the top of the stack.
 * @stack: The stack
 * @line_number: The line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
		return;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - prints the value of the top elmt of the stack
 * @stack: the giving stack
 * @line_number: the line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
		op_error(3, *stack, g_info.opcode, line_number);

	current = *stack;

	printf("%d\n", current->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
		op_error(4, *stack, g_info.opcode, line_number);

	current = *stack;

	*stack = current->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(current);
}


/**
 * _swap - swaps the top two elements of the stack
 * @stack: a pointer the the first element of the stack
 * @line_number: the line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int tmp = 0;

	if (stack_len(*stack) < 2)
		op_error(5, *stack, g_info.opcode, line_number);

	current = *stack;

	tmp = current->n;
	current->n = current->next->n;
	current->next->n = tmp;
}
