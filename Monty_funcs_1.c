#include "monty.h"


void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);


/**
 * monty_push - Pushes a value onto a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp, *new_node;
    int i;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        set_op_tok_error(malloc_error());
        return;
    }

    if (op_toks[1] == NULL)
    {
        set_op_tok_error(no_int_error(line_number));
        return;
    }

    for (i = 0; op_toks[1][i]; i++)
    {
        if (op_toks[1][i] == '-' && i == 0)
            continue;
        if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
        {
            set_op_tok_error(no_int_error(line_number));
            return;
        }
    }
    new_node->n = atoi(op_toks[1]);

    if (check_mode(*stack) == STACK) 
    {
        tmp = (*stack)->next;
        new_node->prev = *stack;
        new_node->next = tmp;
        if (tmp)
            tmp->prev = new_node;
        (*stack)->next = new_node;
    }
    else 
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        new_node->prev = tmp;
        new_node->next = NULL;
        tmp->next = new_node;
    }
}

/**
 * monty_pall - Prints all the  values of a stack_t linked list.
 * @stack: The top node pointer of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = (*stack)->next; // Start from the first node

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next; // Move to the next node
    }

    // Line number is unused in this function
    (void)line_number;
}
/**
 * monty_pint - Displays the top value of a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pint_error(line_number));
        return;
    }

    printf("%d\n", (*stack)->next->n);
}
/**
 * monty_pop - Removes the top element from a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *next = NULL;

    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pop_error(line_number));
        return;
    }

    next = (*stack)->next->next;
    free((*stack)->next);
    if (next)
        next->prev = *stack;
    (*stack)->next = next;
}



/**
 * monty_swap - Swaps the positions of the top two elements in a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "swap"));
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
