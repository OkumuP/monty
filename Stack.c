#include "monty.h"
#include <string.h>


void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);


/**
 * free_stack - Frees a stack.
 * @stack: A pointer to the top or queue stack
 */
void free_stack(stack_t **stack)
{
    stack_t *tmp = *stack;


    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}


/**
 * init_stack - Initializes stack with a beginning stack and ending queue
 * @stack: Initialised stack pointer
 *
 * Return: EXIT_SUCCESS on success otherwise - EXIT_FAILURE.
 */
int init_stack(stack_t **stack)
{
    stack_t *s;


    s = malloc(sizeof(stack_t));
    if (s == NULL)
        return (malloc_error());


    s->n = STACK;
    s->prev = NULL;
    s->next = NULL;


    *stack = s;


    return (EXIT_SUCCESS);
}


/**
 * check_mode - Checks if a linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue) in a list
 *
 * Return: If in stack mode - STACK (0).
 *         If in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
    if (stack->n == STACK)
        return (STACK);
    else if (stack->n == QUEUE)
        return (QUEUE);
    return (2);
}
