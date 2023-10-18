#include "monty.h"

/**
 * global_error - prints global error and exit with EXIT_FAILURE
 * @error_code: the error number
 */

void global_error(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);

	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(args, char *));
			break;
		default:
			break;
	}
	va_end(args);
	exit(EXIT_FAILURE);
}

/**
 * op_error - prints operation error ans exit with EXIT_FAILURE
 * @error_code: the error code
 */

void op_error(int error_code, ...)
{
	va_list args;
	stack_t *stack = NULL;
	char *op;

	va_start(args, error_code);

	stack = va_arg(args, stack_t *);
	op = va_arg(args, char *);

	switch (error_code)
	{
		case 1:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 2:
			fprintf(stderr, "L%d: usage: %s integer\n",
					va_arg(args, int), op);
			break;
		case 3:
			fprintf(stderr, "L%d: can't %s, stack empty\n",
					va_arg(args, int), op);
			break;
		case 4:
			fprintf(stderr, "L%d: can't %s an empty stack\n",
					va_arg(args, int), op);
			break;
		case 5:
			fprintf(stderr, "L%d: can't %s, stack too short\n",
					va_arg(args, int), op);
			break;
		default:
			break;
	}
	free_all(stack);
	exit(EXIT_FAILURE);
}

/**
 * op_error_bis - prints operation error and exit with EXIT_FAILURE
 * @error_code: the error code
 */

void op_error_bis(int error_code, ...)
{
	va_list args;
	stack_t *stack = NULL;
	char *op;

	va_start(args, error_code);
	stack = va_arg(args, stack_t *);
	op = va_arg(args, char *);

	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: unknown instruction %s\n",
					va_arg(args, int), op);
			break;
		case 7:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(args, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't %s, value out of range\n",
					va_arg(args, int), op);
			break;
		default:
			break;
	}
	free_all(stack);
	exit(EXIT_FAILURE);
}
