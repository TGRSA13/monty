#include "monty.h"

void rotlMonty(stack_t **stack, unsigned int line_number);
void rotrMonty(stack_t **stack, unsigned int line_number);
void stackMonty(stack_t **stack, unsigned int line_number);
void queueMonty(stack_t **stack, unsigned int line_number);

/**
 * rotlMonty - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void rotlMonty(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *bottom;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;

    top->next->prev = *stack;
    (*stack)->next = top->next;
    bottom->next = top;
    top->next = NULL;
    top->prev = bottom;

    (void)line_number;
}

/**
 * rotrMonty - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void rotrMonty(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *bottom;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    top = (*stack)->next;
    bottom = (*stack)->next;
    while (bottom->next != NULL)
        bottom = bottom->next;

    bottom->prev->next = NULL;
    (*stack)->next = bottom;
    bottom->prev = *stack;
    bottom->next = top;
    top->prev = bottom;

    (void)line_number;
}

/**
 * stackMonty - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void stackMonty(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = STACK;
    (void)line_number;
}

/**
 * queueMonty - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void queueMonty(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = QUEUE;
    (void)line_number;
}
