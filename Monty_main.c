#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - Entry point for the Monty Interpreter
 *
 * @argc: The count of arguments provided to the program
 * @argv: An array of pointers to character arrays containing arguments
 *
 * Return: Returns EXIT_SUCCESS on success, and EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
    FILE *script_fd = NULL;
    int exit_code = EXIT_SUCCESS;

    if (argc != 2)
        return (usage_error());

    script_fd = fopen(argv[1], "r");
    if (script_fd == NULL)
        return (f_open_error(argv[1]));

    exit_code = run_monty(script_fd);

    fclose(script_fd);

    return (exit_code);
}
