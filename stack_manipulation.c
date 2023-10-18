#include "monty.h"

/**
 * add_nodeint_end - adds a new node the end of the stack
 * @h: the head of the stack
 * @n: the node data
 * Return: The address of the new node
*/
stack_t *add_nodeint_end(stack_t **h, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		op_error(1, *h, g_info.opcode);
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*h == NULL)
		*h = new;
	else
	{
		new->next = *h;
		(*h)->prev = new;
		*h = new;
	}
	return (new);
}


/**
 * stack_free - frees the stack
 * @head: The head of the stack
 */
void stack_free(stack_t *head)
{
	stack_t *current = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

/**
 * len_stack - return stack length
 * @head: the giving stack
 * Return: the length of the stack
 */
int len_stack(stack_t *head)
{
	stack_t *tmp = head;
	int len = 0;

	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

/**
 * queue_node_add - adds a node at the end of a queue
 * @h: a pointer to the top of a stack
 * @n: the integer to be added
 * Return: a pointer to the new node
 */
stack_t *queue_node_add(stack_t **h, const int n)
{
	stack_t *new, *current;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		op_err(1, *h);
	new->n = n;
	new->next = NULL;

	if (*h == NULL)
	{
		*h = new;
		new->prev = NULL;
	}
	else
	{
		current = *h;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
	return (new);
}
