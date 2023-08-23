#include "monty.h"


void monty_rotat(stack_t **stack, unsigned int line_number);
void monty_rot(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);


/**
 * monty_rotat - Rotates the top value to the bottom of the stack.
 * @stack: The top node pointer of a stack_t linked list.
 * @line_number: The current line number of a Monty bytecodes file.
 */
void monty_rotat(stack_t **stack, unsigned int line_number)
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
 * monty_rot - Rotates the bottom value to the top of a stack.
 * @stack: The top node ponter of a stack_t linked list.
 * @line_number: The current line number of a Monty bytecodes file.
 */
void monty_rot(stack_t **stack, unsigned int line_number)
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
 * monty_stack - This changes a queue into a stack
 * @stack: The top node pointer of a stack_t linked list.
 * @line_number: The current line number of a Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = STACK;
    (void)line_number;
}


/**
 * monty_queue - Changes a stack to a queue.
 * @stack: The top node pointer of a stack_t linked list.
 * @line_number: The current line number of a Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
    (*stack)->n = QUEUE;
    (void)line_number;
}
