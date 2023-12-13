#include "monty.h"

void pushMonty(stack_t **stack, unsigned int line_number);
void printAllMonty(stack_t **stack, unsigned int line_number);
void printTopMonty(stack_t **stack, unsigned int line_number);
void popMonty(stack_t **stack, unsigned int line_number);
void swapMonty(stack_t **stack, unsigned int line_number);

/**
 * pushMonty - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pushMonty(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp, *newNode;
    int i;

    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        setOpTokError(malloc_error());
        return;
    }

    if (op_toks[1] == NULL)
    {
        setOpTokError(no_int_error(line_number));
        return;
    }

    for (i = 0; op_toks[1][i]; i++)
    {
        if (op_toks[1][i] == '-' && i == 0)
            continue;
        if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
        {
            setOpTokError(no_int_error(line_number));
            return;
        }
    }

    newNode->n = atoi(op_toks[1]);

    if (checkMode(*stack) == STACK) /* STACK mode insert at front */
    {
        tmp = (*stack)->next;
        newNode->prev = *stack;
        newNode->next = tmp;
        if (tmp)
            tmp->prev = newNode;
        (*stack)->next = newNode;
    }
    else /* QUEUE mode insert at end */
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        newNode->prev = tmp;
        newNode->next = NULL;
        tmp->next = newNode;
    }
}

/**
 * printAllMonty - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void printAllMonty(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = (*stack)->next;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    (void)line_number;
}

/**
 * printTopMonty - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void printTopMonty(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        setOpTokError(pint_error(line_number));
        return;
    }

    printf("%d\n", (*stack)->next->n);
}

/**
 * popMonty - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void popMonty(stack_t **stack, unsigned int line_number)
{
    stack_t *next = NULL;

    if ((*stack)->next == NULL)
    {
        setOpTokError(pop_error(line_number));
        return;
    }

    next = (*stack)->next->next;
    free((*stack)->next);
    if (next)
        next->prev = *stack;
    (*stack)->next = next;
}

/**
 * swapMonty - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void swapMonty(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setOpTokError(short_stack_error(line_number, "swap"));
        return;
    }

    tmp = (*stack)->next->next;
    (*stack)->next->next = tmp->next;
    (*stack)->next->prev = tmp;
    if (tmp->next)
        tmp->next->prev = (*stack)->next;
    tmp->next = (*stack)->next;
    tmp->prev = *stack;
    (*stack)->next = tmp;
}
