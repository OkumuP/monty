#include "monty.h"

int pchar_error(unsigned int line_number, char *message);
int div_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
/**
 * pop_error - Outputs an error message for attempting to pop an empty stack.
 * @line_number: Line number in the script where the error occurred.
 *
 * Return: Always returns EXIT_FAILURE.
 */
int pop_error(unsigned int line_number)
{
    fprintf(stderr, "Error: Attempted to pop an empty stack at line %u\n", line_number);
    return (EXIT_FAILURE);
}
/**
 * print_error - Outputs an error message for attempting to pint an empty stack.
 * @line_number: The line number in the Monty bytecode file where the error occurred.
 *
 * Return: Always returns EXIT_FAILURE.
 */
int print_error(unsigned int line_number)
{
    fprintf(stderr, "Error: Attempted to pint an empty stack at line %u\n", line_number);
    return (EXIT_FAILURE);
}
/**
 * short_stack_error - Outputs an error message for math operations on stacks/queues
 *                            with fewer than two nodes.
 * @line_number: The line number in the Monty bytecode file where the error occurred.
 * @op: The operation that caused the error.
 *
 * Return: Always returns EXIT_FAILURE.
 */
int short_stack_error(unsigned int line_number, char *op)
{
    fprintf(stderr, "Error: Can't perform '%s', stack/queue too short at line %u\n", op, line_number);
    return (EXIT_FAILURE);
}
/**
 * div_error - Outputs an error message for division by zero.
 * @line_number: The line number in the Monty bytecode file where the error occurred.
 *
 * Return: Always returns EXIT_FAILURE.
 */
int div_error(unsigned int line_number)
{
    fprintf(stderr, "Error: Division by zero at line %u\n", line_number);
    return (EXIT_FAILURE);
}
/**
 * pchar_error - Outputs an error message for pchar errors,
 *                      including empty stacks and non-character values.
 * @line_number: The line number in the Monty bytecode file where the error occurred.
 * @message: The specific error message to print.
 *
 * Return: Always returns EXIT_FAILURE.
 */
int pchar_error(unsigned int line_number, char *message)
{
    fprintf(stderr, "Error: Unable to execute 'pchar', %s at line %u\n", message, line_number);
    return (EXIT_FAILURE);
}
