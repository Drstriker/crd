/*
** ETNA PROJECT, 03/11/2020 by yu_t
** [...]
** File description:
**      [...]
*/

#include "my_crd.h"

void    commands_manager(char **tab, linked_list_t **list)
{
    unsigned int key = my_getnbr(tab[0]);
    unsigned int value = 0;

    if (tab[1]) {
        value = my_getnbr(tab[1]);
        if (tab[0] && my_strisnum(tab[1]) && my_strcmp(tab[1], "D") != 0) {
            insert_command(key, value, list);
        } else if (my_strcmp(tab[1], "D") == 0) {
            remove_command(key, *list);
        }
    } else {
        lookup_command(key, *list);
    }
}

void    insert_command(unsigned int key, unsigned int value,
                        linked_list_t **list)
{
    if (my_find_node(key, *list) == 0) {
        *list = my_push_front_to_list(key, value, *list);
        my_putnbr(key);
        my_putchar('\n');
    } else {
        my_change_value_list(key, value, *list);
        my_putnbr(key);
        my_putchar('\n');
    }
}

void    lookup_command(unsigned int key, linked_list_t *list)
{
    unsigned int value = my_find_node(key, list);

    if (value == 0) {
        my_putstr("-1\n");
    } else {
        my_putnbr(value);
        my_putchar('\n');
    }
}

void    remove_command(unsigned int key, linked_list_t *list)
{
    unsigned int value = my_find_node(key, list);

    if (value != 0) {
        my_delete_nodes(key, list);
        my_putnbr(value);
        my_putchar('\n');
    } else {
        my_putstr("-1\n");
    }
}
