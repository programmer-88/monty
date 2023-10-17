TEAM PROJECT : Stacks, Queues - LIFO, FIFO Project
The goal of this project is to create an interpreter for Monty ByteCodes files

Compilation & Output
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

Requirements
Usage: monty file
Any output must be printed on stdout
Any error message must be printed on stderr
There is not more than one instruction per line
There can be any number of spaces before or after the opcode and its argument
The monty program runs the bytecodes line by line and stop if either:
it executed properly every line of the file
it finds an error in the file
an error occured
If the user does not give any file or more than one argument to your program, we print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
if the file contains an invalid instruction, we print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
Line numbers always start at 1
If we can’t malloc anymore, we print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE
We suppose to use Those structures : /**
struct stack_s - doubly linked list representation of a stack (or queue)
@n: integer
@prev: points to the previous element of the stack (or queue)
@next: points to the next element of the stack (or queue)
Description: doubly linked list node structure
for stack, queues, LIFO, FIFO */ typedef struct stack_s { int n; struct stack_s *prev; struct stack_s *next; } stack_t;
/**

struct instruction_s - opcode and its function
@opcode: the opcode
@f: function to handle the opcode
Description: opcode and its function
for stack, queues, LIFO, FIFO */ typedef struct instruction_s { char *opcode; void (*f)(stack_t **stack, unsigned int line_number); } instruction_t;
Monty Instructions
Operation Code	Description
push	* pushes an element to the stack
* Usage: push
* if is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
pall	* prints all the values on the stack, starting from the top of the stack
* Usage: pall
* If the stack is empty, we don’t print anything
pint	* prints the value at the top of the stack, followed by a new line
* Usage: pint
* If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE
pop	* removes the top element of the stack
* Usage: pop
* If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE
swap	* swaps the top two elements of the stack
* Usage: swap
* If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
add	* adds the top two elements of the stack
* Usage: add
* If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed
nop	* doesn’t do anything
* Usage: nop
sub	* subtracts the top element of the stack from the second top element of the stack
* Usage: sub
* If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed
div	* divides the second top element of the stack by the top element of the stack
* Usage: div
* If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed
* If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE
mul	* multiplies the second top element of the stack with the top element of the stack
* Usage: mul
* If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed
mod	* computes the rest of the division of the second top element of the stack by the top element of the stack
* Usage: mod
* If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed
* If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE
Comment	* When the first non-space character of a line is #, we treat this line as a comment (we don’t do anything)
pchar	* prints the char at the top of the stack, followed by a new line
* Usage: pchar
* The integer stored at the top of the stack is treated as the ascii value of the character to be printed
* If the value is not in the ascii table (man ascii) print the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE
* If the stack is empty, print the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE
pstr	* prints the string starting at the top of the stack, followed by a new line
* Usage: pstr
* The integer stored in each element of the stack is treated as the ascii value of the character to be printed
* The string stops when either: 1/the stack is over 2/the value of the element is 0 3/the value of the element is not in the ascii table
* If the stack is empty, print only a new line
rotl	* rotates the stack to the top
* Usage: rotl
* The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
* rotl never fails
rotr	* rotates the stack to the bottom
* Usage: rotr
* The last element of the stack becomes the top element of the stack
stack	* sets the format of the data to a stack (LIFO). This is the default behavior of the program
* Usage: stack
* The top of the stack becomes the front of the queue
queue	* sets the format of the data to a queue (FIFO)
* Usage: queue
* The front of the queue becomes the top of the stack

