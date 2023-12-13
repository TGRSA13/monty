#include "monty.h"

void addMonty(stack_t **stack, unsigned int line_number);
void subMonty(stack_t **stack, unsigned int line_number);
void divMonty(stack_t **stack, unsigned int line_number);
void mulMonty(stack_t **stack, unsigned int line_number);
void modMonty(stack_t **stack, unsigned int line_number);

/**
 * addMonty - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top, and the top value is removed.
 */
void addMonty(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setOpTokError(short_stack_error(line_number, "add"));
        return;
    }

    (*stack)->next->next->n += (*stack)->next->n;
    popMonty(stack, line_number);
}

/**
 * subMonty - Subtracts the second value from the top of
 *            a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top, and the top value is removed.
 */
void subMonty(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setOpTokError(short_stack_error(line_number, "sub"));
        return;
    }

    (*stack)->next->next->n -= (*stack)->next->n;
    popMonty(stack, line_number);
}

/**
 * divMonty - Divides the second value from the top of
 *            a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top, and the top value is removed.
 */
void divMonty(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setOpTokError(short_stack_error(line_number, "div"));
        return;
    }

    if ((*stack)->next->n == 0)
    {
        setOpTokError(div_error(line_number));
        return;
    }

    (*stack)->next->next->n /= (*stack)->next->n;
    popMonty(stack, line_number);
}

/**
 * mulMonty - Multiplies the second value from the top of
 *            a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top, and the top value is removed.
 */
void mulMonty(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setOpTokError(short_stack_error(line_number, "mul"));
        return;
    }

    (*stack)->next->next->n *= (*stack)->next->n;
    popMonty(stack, line_number);
}

/**
 * modMonty - Computes the modulus of the second value from the
 *            top of a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top, and the top value is removed.
 */
void modMonty(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        setOpTokError(short_stack_error(line_number, "mod"));
        return;
    }

    if ((*stack)->next->n == 0)
    {
        setOpTokError(div_error(line_number));
        return;
    }

    (*stack)->next->next->n %= (*stack)->next->n;
    popMonty(stack, line_number);
}
