#include <stdlib.h>


char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
               char *buff, int buff_size);
/**
 * get_int - Converts an integer to a string.
 * @num: The integer to convert.
 *
 * Return: A character pointer to the newly created string, or NULL if it fails
 */
char *get_int(int num)
{
    unsigned int temp;
    int length = 0;
    long num_l = 0;
    char *result;

    temp = _abs(num);
    length = get_numbase_len(temp, 10);

    if (num < 0 || num_l < 0)
        length++; /* Consider negative sign */

    result = malloc(length + 1); /* Create a new string */
    if (!result)
        return (NULL);

    fill_numbase_buff(temp, 10, result, length);
    if (num < 0 || num_l < 0)
        result[0] = '-';

    return (result);
}

/**
 * _abs - Computes the absolute value of an integer.
 * @i: The integer to determine the absolute value of.
 *
 * Return: An unsigned integer representing the absolute value of 'i'.
 */
unsigned int _abs(int i)
{
    if (i < 0)
        return (-(unsigned int)i);
    return ((unsigned int)i);
}

/**
 * get_numbase_len - Computes the length of a buffer required for an unsig int
 * @num: The number for which the buffer length is calculated.
 * @base: The base of the number representation used by the buffer.
 *
 * Return: An int representing the length of the buffer needed (exc null byte).
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
    int length = 1; 

    while (num > base - 1)
    {
        length++;
        num /= base;
    }

    return (length);
}
/**
 * fill_numbase_buff - Fills a buffer with the string representation of
 * an unsigned integer in the given base (up to 36).
 * @num: The number to convert to a string.
 * @base: The base for the conversion (works up to base 36).
 * @buff: The buffer to fill with the result of the conversion.
 * @buff_size: The size of the buffer in bytes.
 *
 * Return: Always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
                       char *buff, int buff_size)
{
    int rem, i = buff_size - 1;

    buff[buff_size] = '\0';
    while (i >= 0)
    {
	    rem = num % base;
        if (rem > 9) /* Convert to lowercase ASCII character representation */
            buff[i] = rem + 87; /* 10 will be 'a', 11 will be 'b', ... */
        else
            buff[i] = rem + '0';
        num /= base;
        i--;
    }
}
