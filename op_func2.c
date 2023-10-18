#include "monty.h"

/**
 * mod - computes the rest of the division of the two top
 * elements of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current;


	if (len_stack(*stack) < 2)
		op_err(5, *stack, g_info.opcode, line_number);

	current = *stack;

	*stack = current->next;
	if (current->n == 0)
		op_error_fail(7, *stack, g_info.opcode, line_number);
	(*stack)->n = (*stack)->n % current->n;
	(*stack)->prev = NULL;
	free(current);
}


/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (!stack || !(*stack))
		op_err(3, *stack, g_info.opcode, line_number);

	current = *stack;

	if (current->n >= 0  && current->n <= 127)
		printf("%c\n", current->n);
	else
		op_error_fail(8, *stack, g_info.opcode, line_number);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;

	current = *stack;


	while (current != NULL)
	{
		if (current->n > 0  && current->n <= 127)
			printf("%c", current->n);
		else
			break;
		current = current->next;
	}
	printf("\n");
}


/**
 * rotl - rotates the stack to the top
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *tmp;

	(void)line_number;
	if (!stack || !(*stack) || len_stack(*stack) == 1)
		return;

	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = NULL;

	current = *stack;

	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->prev = current;
	tmp->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: a pointer to the first node of the stack
 * @line_number: the line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	if (!stack || !(*stack) || len_stack(*stack) == 1)
		return;

	current = *stack;

	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	if (current->prev != NULL)
		(current->prev)->next = NULL;
	current->prev = NULL;
	(*stack)->prev = current;
	*stack = current;
}
