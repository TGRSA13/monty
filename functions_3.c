#include "monty.h"

void nopMonty(stack_t **stack, unsigned int line_number);
void pcharMonty(stack_t **stack, unsigned int line_number);
void pstrMonty(stack_t **stack, unsigned int line_number);

/**
 * nopMonty - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void nopMonty(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * pcharMonty - Prints the character in the top value
 *              node of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pcharMonty(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        setOpTokError(pchar_error(line_number, "stack empty"));
        return;
    }
    if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
    {
        setOpTokError(pchar_error(line_number, "value out of range"));
        return;
    }

    printf("%c\n", (*stack)->next->n);
}

/**
 * pstrMonty - Prints the string contained in a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pstrMonty(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;

    while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
    {
        printf("%c", tmp->n);
        tmp = tmp->next;
    }

    printf("\n");

    (void)line_number;
}
