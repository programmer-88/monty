#include "monty.h"

/**
 * get_op_func - get operation function
 * @opcode: the operation code
 * Return: Return the associate function, or NULL if not found
 */
void (*op_func_get(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
