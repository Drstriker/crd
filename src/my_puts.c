/*
** ETNA PROJECT, 02/11/2020 by yu_t
** [...]
** File description:
**      [...]
*/

#include "my_crd.h"

void    my_putchar(char c)
{
    write(1, &c, 1);
}

void    my_putstr(char *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}

void    my_putnbr(unsigned int nb)
{
    int mod;

    if (nb >= 4294967295) {
        my_putstr("4294967295");
        return;
    }
    if (nb >= 10) {
        mod = (nb % 10);
        nb = (nb - mod) / 10;
        my_putnbr(nb);
        my_putchar(48 + mod);
    } else {
        my_putchar(48 + nb % 10);
    }
}

void    print_list(linked_list_t *list)
{
    linked_list_t   *new_list = list;

    while (new_list) {
        my_putnbr(new_list->key);
        if (new_list->value) {
            my_putchar(' ');
            my_putnbr(new_list->value);
        }
        new_list = new_list->next;
        my_putchar('\n');
    }
}