/*
** ETNA PROJECT, 03/11/2020 by yu_t
** [...]
** File description:
**      [...]
*/

#include "my_crd.h"

int is_alphanum(char c)
{
    if (((c >= 'a') && (c <= 'z')) ||
        ((c >= 'A') && (c <= 'Z')) ||
        ((c >= '0') && (c <= '9')))
        return 1;
    else
        return 0;
}

int getnb_word(char *str)
{
    int word = 0;
    int i = 0;
    while (str[i]) {
        if (is_alphanum(str[i])) {
            word++;
            while (is_alphanum(str[i]))
                i++;
        }
        i++;
    }
    return word;
}

char **my_str_to_word_array(char *str)
{
    int i = 0;
    int i_word = 0;
    int wordlen = 0;
    char **wordtab;
    
    wordtab = malloc(sizeof(char *) * (getnb_word(str) + 1));
    while (str[i]) {
        if (is_alphanum(str[i])) {
            i_word++;
            wordlen = 0;
            while (is_alphanum(str[i])) {
                i++;
                wordlen++;
            }
            wordtab[i_word - 1] = my_strdup(str + i - wordlen);
            wordtab[i_word - 1][wordlen] = '\0';
        }
        if (str[i] == '\0')
            break;
        i++;
    }
    wordtab[i_word] = NULL;
    return (wordtab);
}
