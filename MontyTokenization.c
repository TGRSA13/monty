#include <stdlib.h>


char **monty_strtow(char *str, char *delims);
int monty_is_delim(char ch, char *delims);
int monty_get_word_length(char *str, char *delims);
int monty_get_word_count(char *str, char *delims);
char *monty_get_next_word(char *str, char *delims);


/**
 * monty_strtow - takes a string and separates its words
 *
 * @str: string to separate into words
 * @delims: delimiters to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */


char **monty_strtow(char *str, char *delims)
{
    char **words = NULL;
    int wc, wordLen, n, i = 0;


    if (str == NULL || !*str)
        return (NULL);
    wc = monty_get_word_count(str, delims);


    if (wc == 0)
        return (NULL);
    words = malloc((wc + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);
    while (i < wc)
    {
        wordLen = monty_get_word_length(str, delims);
        if (monty_is_delim(*str, delims))
        {
            str = monty_get_next_word(str, delims);
        }
        words[i] = malloc((wordLen + 1) * sizeof(char));
        if (words[i] == NULL)
        {
            while (i >= 0)
            {
                i--;
                free(words[i]);
            }
            free(words);
            return (NULL);
        }
        n = 0;
        while (n < wordLen)
        {
            words[i][n] = *(str + n);
            n++;
        }
        words[i][n] = '\0'; /* set end of str */
        str = monty_get_next_word(str, delims);
        i++;
    }
    words[i] = NULL; /* last element is null for iteration */
    return (words);
}


/**
 * monty_is_delim - checks if stream has delimiter char
 *
 * @ch: character in stream
 *
 * @delims: Pointer to null-terminated array of delimiters
 *
 * Return: 1 (success) 0 (failure)
 */


int monty_is_delim(char ch, char *delims)
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
 * monty_get_word_length - gets the word length of current word in str
 *
 * @str: string to get word length from current word
 * @delims: delimiters to use to delimit words
 *
 * Return: word length of current word
 */


int monty_get_word_length(char *str, char *delims)
{
    int wLen = 0, pending = 1, i = 0;


    while (*(str + i))
    {
        if (monty_is_delim(str[i], delims))
            pending = 1;
        else if (pending)
        {
            wLen++;
        }
        if (wLen > 0 && monty_is_delim(str[i], delims))
            break;
        i++;
    }
    return (wLen);
}


/**
 * monty_get_word_count - gets the word count of a string
 *
 * @str: string to get word count from
 * @delims: delimiters to use to delimit words
 *
 * Return: the word count of the string
 */


int monty_get_word_count(char *str, char *delims)
{
    int wc = 0, pending = 1, i = 0;


    while (*(str + i))
    {
        if (monty_is_delim(str[i], delims))
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
 * monty_get_next_word - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimiters to use to delimit words
 *
 * Return: pointer to the first char of the next word
 */


char *monty_get_next_word(char *str, char *delims)
{
    int pending = 0;
    int i = 0;


    while (*(str + i))
    {
        if (monty_is_delim(str[i], delims))
            pending = 1;
        else if (pending)
            break;
        i++;
    }
    return (str + i);
}
