#include "monty.h"
#include <string.h>

void releaseTokens(void);
unsigned int tokenArrayLength(void);
int isEmptyLine(char *line, char *delimiters);
void (*getOperationFunction(char *opcode))(stack_t**, unsigned int);
int executeMonty(FILE *scriptFile);

/**
 * releaseTokens - Frees the global op_toks array of strings.
 */
void releaseTokens(void)
{
    size_t i = 0;

    if (op_toks == NULL)
        return;

    for (i = 0; op_toks[i]; i++)
        free(op_toks[i]);

    free(op_toks);
}

/**
 * tokenArrayLength - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int tokenArrayLength(void)
{
    unsigned int tokensLength = 0;

    while (op_toks[tokensLength])
        tokensLength++;
    return (tokensLength);
}

/**
 * isEmptyLine - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delimiters: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int isEmptyLine(char *line, char *delimiters)
{
    int i, j;

    for (i = 0; line[i]; i++)
    {
        for (j = 0; delimiters[j]; j++)
        {
            if (line[i] == delimiters[j])
                break;
        }
        if (delimiters[j] == '\0')
            return (0);
    }

    return (1);
}

/**
 * getOperationFunction - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*getOperationFunction(char *opcode))(stack_t**, unsigned int)
{
    instruction_t opFunctions[] = {
        {"push", monty_push},
        {"pall", monty_pall},
        {"pint", monty_pint},
        {"pop", monty_pop},
        {"swap", monty_swap},
        {"add", monty_add},
        {"nop", monty_nop},
        {"sub", monty_sub},
        {"div", monty_div},
        {"mul", monty_mul},
        {"mod", monty_mod},
        {"pchar", monty_pchar},
        {"pstr", monty_pstr},
        {"rotl", monty_rotl},
        {"rotr", monty_rotr},
        {"stack", monty_stack},
        {"queue", monty_queue},
        {NULL, NULL}
    };
    int i;

    for (i = 0; opFunctions[i].opcode; i++)
    {
        if (strcmp(opcode, opFunctions[i].opcode) == 0)
            return (opFunctions[i].f);
    }

    return (NULL);
}

/**
 * executeMonty - Primary function to execute a Monty bytecodes script.
 * @scriptFile: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int executeMonty(FILE *scriptFile)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0, exitStatus = EXIT_SUCCESS;
    unsigned int line_number = 0, prevTokenLength = 0;
    void (*opFunction)(stack_t**, unsigned int);

    if (initStack(&stack) == EXIT_FAILURE)
        return (EXIT_FAILURE);

    while (getline(&line, &len, scriptFile) != -1)
    {
        line_number++;
        op_toks = strtow(line, DELIMITERS);
        if (op_toks == NULL)
        {
            if (isEmptyLine(line, DELIMITERS))
                continue;
            freeStack(&stack);
            return (malloc_error());
        }
        else if (op_toks[0][0] == '#') /* comment line */
        {
            releaseTokens();
            continue;
        }
        opFunction = getOperationFunction(op_toks[0]);
        if (opFunction == NULL)
        {
            freeStack(&stack);
            exitStatus = unknown_op_error(op_toks[0], line_number);
            releaseTokens();
            break;
        }
        prevTokenLength = tokenArrayLength();
        opFunction(&stack, line_number);
        if (tokenArrayLength() != prevTokenLength)
        {
            if (op_toks && op_toks[prevTokenLength])
                exitStatus = atoi(op_toks[prevTokenLength]);
            else
                exitStatus = EXIT_FAILURE;
            releaseTokens();
            break;
        }
        releaseTokens();
    }
    freeStack(&stack);

    if (line && *line == 0)
    {
        free(line);
        return (malloc_error());
    }

    free(line);
    return (exitStatus);
}
