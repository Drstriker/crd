/*
** ETNA PROJECT, 03/11/2020 by yu_t
** [...]
** File description:
**      [...]
*/

#include "my_crd.h"

linked_list_t   *my_push_front_to_list(unsigned int key, unsigned int value,
                                        linked_list_t *list)
{
    linked_list_t *new_list;

    if ((new_list = malloc(sizeof(linked_list_t))) == NULL)
        return (NULL);
    new_list->key = key;
    new_list->value = value;
    if (list == NULL)
        new_list->next = NULL;
    else
        new_list->next = list;
    return new_list;
}

void            my_delete_nodes(unsigned int key, linked_list_t **list)
{
    linked_list_t   *new_list = *list;
    linked_list_t   *tmp;

    if (new_list && (new_list->key == key)) {
        *list = new_list->next;
        free(new_list);
        return;
    }

    while ((new_list) && (new_list->key != key)) {
        tmp = new_list;
        new_list = new_list->next;
    }
    if (new_list == NULL)
        return;
    tmp->next = new_list->next;
    free(new_list);
}

unsigned int    my_find_node(unsigned int key, linked_list_t *list)
{
    linked_list_t   *new_list = list;

    if (list == NULL)
        return 0;
    while (new_list) {
        if (new_list->key == key) {
            return new_list->value;
        }
        new_list = new_list->next;
    }
    return 0;
}

linked_list_t   *my_change_value_list(unsigned int key, unsigned int value,
                                        linked_list_t *list)
{
    linked_list_t   *new_list = list;

    if (list == NULL)
        return 0;
    while (new_list) {
        if (new_list->key == key) {
            new_list->value = value;
            return new_list;
        }
        new_list = new_list->next;
    }
    return NULL;
}