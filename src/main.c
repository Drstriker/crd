/*
** ETNA PROJECT, 02/11/2020 by yu_t
** [...]
** File description:
**      [...]
*/

#include "my_crd.h"

int main()
{
    char            *str = NULL;
    char            **tab = NULL;
    linked_list_t   *list = NULL;

    while ((str = my_readline())) {
        if (my_strcmp(str, "\0") != 0) {
            tab = my_str_to_word_array(str);
            commands_manager(tab, &list);
            free(tab);
        }
        free(str);
    }
    free(list);
    return 0;
}
