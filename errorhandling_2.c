#include "monty.h"

int handleShortStackError(unsigned int line_number, char *operation);
int handleDivisionError(unsigned int line_number);
int handlePopError(unsigned int line_number);
int handlePintError(unsigned int line_number);
int handlePcharError(unsigned int line_number, char *message);

/**
 * handlePopError - Prints pop error messages for empty stacks.
 * @line_number: Line number in script where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handlePopError(unsigned int line_number)
{
fprintf(stderr, "Line %u: Can't pop an empty stack\n", line_number);
return (EXIT_FAILURE);
}

/**
 * handlePintError - Prints pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handlePintError(unsigned int line_number)
{
fprintf(stderr, "Line %u: Can't pint, stack empty\n", line_number);
return (EXIT_FAILURE);
}

/**
 * handleShortStackError - Prints monty math function error messages
 *                         for stacks/queues smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where error occurred.
 * @operation: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleShortStackError(unsigned int line_number, char *operation)
{
fprintf(stderr, "Line %u: Can't %s, stack too short\n", line_number, operation);
return (EXIT_FAIL);
}
