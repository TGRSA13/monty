#include "monty.h"

int displayUsageError(void);
int handleMemoryAllocationError(void);
int handleFileOpenError(char *filename);
int handleUnknownOperationError(char *opcode, unsigned int line_number);
int handleNoIntegerError(unsigned int line_number);

/**
 * displayUsageError - Prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int displayUsageError(void)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

/**
 * handleMemoryAllocationError - Prints memory allocation error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleMemoryAllocationError(void)
{
fprintf(stderr, "Error: Memory allocation failed\n");
return (EXIT_FAILURE);
}

/**
 * handleFileOpenError - Prints file opening error messages with file name.
 * @filename: Name of the file that failed to open.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleFileOpenError(char *filename)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}

/**
 * handleUnknownOperationError - Prints unknown instruction error messages.
 * @opcode: Opcode where the error occurred.
 * @line_number: Line number in Monty bytecodes file where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleUnknownOperationError(char *opcode, unsigned int line_number)
{
fprintf(stderr, "Line %u: Unknown instruction %s\n", line_number, opcode);
return (EXIT_FAILURE);
}

/**
 * handleNoIntegerError - Prints invalid monty_push argument error messages.
 * @line_number: Line number in Monty bytecodes file where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleNoIntegerError(unsigned int line_number)
{
fprintf(stderr, "Line %u: Usage: push integer\n", line_number);
return (EXIT_FAILURE);
}
