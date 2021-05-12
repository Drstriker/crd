/*
** ETNA PROJECT, 02/11/2020 by yu_t
** [...]
** File description:
**      [...]
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _MY_CRD_H_
# define _MY_CRD_H_

typedef struct  linked_list_s
{
    unsigned int            key;
    unsigned int            value;
    struct linked_list_s    *next;
}               linked_list_t;

/*
**  my_puts.c
*/

void            my_putchar(char);
void            my_putstr(char *);
void            my_putnbr(unsigned int);
void            print_list(linked_list_t *);

/*
**  my_getnbr.c
*/

int             is_num_or_sign(char);
int             is_out_of_bound(int);
int             get_sign(char *);
int             check_validity(char *);
unsigned int    my_getnbr(char *);

/*
**  my_lists.c
*/

linked_list_t   *my_push_front_to_list(unsigned int, unsigned int, linked_list_t *);
void            my_delete_nodes(unsigned int, linked_list_t **);
unsigned int    my_find_node(unsigned int, linked_list_t *);
linked_list_t   *my_change_value_list(unsigned int, unsigned int, linked_list_t *);

/*
**  my_strops.c
*/

int             my_strlen(char *);
char	        *my_strcpy(char *, char *);
char            *my_strdup(char *);
int             my_strcmp(char *, char *);
int             my_strisnum(char *);

/*
**  my_str_to_word_array.c
*/

int             is_alphanum(char);
int             is_neg(char *);
int             is_num(char);
int             getnb_word(char *);
char            **my_str_to_word_array(char *);

/*
**  my_readline.c
*/

char            *my_readline(void);

/*
**  commands.c
*/

void            commands_manager(char **, linked_list_t **);
void            insert_command(unsigned int, unsigned int, linked_list_t **);
void            lookup_command(unsigned int, linked_list_t *);
void            remove_command(unsigned int, linked_list_t *);

#endif /* MY_CRD_H */