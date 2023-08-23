#include <stdlib.h>


char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);


/**
 * strtow - separates a string into words
 *
 * @str: the string to separate
 * @delims: delimiters for words
 *
 * Return: Array of pointers to each word
 */


char **strtow(char *str, char *delims)
{
    char **tokens = NULL;
    int token_count, token_length, n, i = 0;

    if (str == NULL || !*str)
        return (NULL);

    token_count = count_tokens(str, delims);

    if (token_count == 0)
        return (NULL);

    tokens = malloc((token_count + 1) * sizeof(char *));
    if (tokens == NULL)
        return (NULL);

    while (i < token_count)
    {
        token_length = token_length(str, delims);
        if (is_delim(*str, delims))
        {
            str = next_token(str, delims);
        }

        tokens[i] = malloc((token_length + 1) * sizeof(char));
        if (tokens[i] == NULL)
        {
            while (i >= 0)
            {
                i--;
                free(tokens[i]);
            }
            free(tokens);
            return (NULL);
        }

        n = 0;
        while (n < token_length)
        {
            tokens[i][n] = *(str + n);
            n++;
        }
        tokens[i][n] = '\0';
        str = next_token(str, delims);
        i++;
    }
    tokens[i] = NULL;
    return (tokens);
}



/**
 * is_delim - Check if a stream has a delimeter
 *
 * @ch: character in stream
 *
 * @delims: The null terminated array pointer of delimitors
 *
 * Return: 1 on succes and  0 failure
 */


int is_delim(char ch, char *delims)
{
    int i = 0;


    while (delims[i])
    {
        if (delims[i] == ch)
            return (1);
        i++;
    }
    return (0);
}


/**
 * get_word_length - Gets word length
 *
 * @str: string to get word length from
 * @delims: delimitors
 *
 * Return: Length of the current word
 */


int get_word_length(char *str, char *delims)
{
    int wLen = 0, pending = 1, i = 0;


    while (*(str + i))
    {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending)
        {
            wLen++;
        }
        if (wLen > 0 && is_delim(str[i], delims))
            break;
        i++;
    }
    return (wLen);
}


/**
 * get_word_count - Count words of a string
 *
 * @str: string 
 * @delims: delimitors
 *
 * Return: total word count of the string
 */


int get_word_count(char *str, char *delims)
{
    int wc = 0, pending = 1, i = 0;


    while (*(str + i))
    {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending)
        {
            pending = 0;
            wc++;
        }
        i++;
    }
    return (wc);
}


/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get the next word of
 * @delims: delimitors
 *
 * Return: first char pointer of the word
 */


char *get_next_word(char *str, char *delims)
{
    int pending = 0;
    int i = 0;


    while (*(str + i))
