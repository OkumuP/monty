#include "monty.h"


/**
 * set_op_tok_error - Sets the last element of op_toks to an error code.
 * @error_code: An integer representing the error code.
 */
void set_op_tok_error(int error_code)
{
    int toks_len = 0, i = 0;
    char *exit_code_str = NULL;
    char **new_tokens = NULL;

    toks_len = token_arr_len();
    new_tokens = malloc(sizeof(char *) * (toks_len + 2));
    if (!op_toks)
    {
        malloc_error();
        return;
    }
    while (i < toks_len)
    {
        new_tokens[i] = op_toks[i];
        i++;
    }
    exit_code_str = get_int(error_code);
    if (!exit_code_str)
    {
        free(new_tokens);
        malloc_error();
        return;
    }
    new_tokens[i++] = exit_code_str;
    new_tokens[i] = NULL;
    free(op_toks);
    op_toks = new_tokens;
}
