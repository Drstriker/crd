/*
** ETNA PROJECT, 02/11/2020 by yu_t
** [...]
** File description:
**      [...]
*/

#include "my_crd.h"

int     is_num_or_sign(char c)
{
    if ((c >= '0') && (c <= '9'))
        return 1;
    else if ((c == '+') || (c == '-'))
        return 2;
    else
        return 0;
}

int     is_out_of_bound(int nb)
{
    if (((unsigned int)nb <= 0) || ((unsigned int)nb > 4294967294))
        return 1;
    else
        return 0;
}

int     get_sign(char *str)
{
    int i = 0;
    int sign = 0;

    while (is_num_or_sign(str[i]) == 2) {
        if (str[i] == '-')
            sign++;
        i++;
    }
    if ((sign % 2) == 0)
        return (1);
    else
        return (-1);
}

int     check_validity(char *str)
{
    int i = 0;

    while (is_num_or_sign(str[i]) == 2) {
        if (is_num_or_sign(str[i]) == 0) {
            return (-1);
        }
        i++;
    }
    return (i);
}

unsigned int     my_getnbr(char *str)
{
    int i = check_validity(str);
    int nb = 0;
    int sign = get_sign(str);

    if (i == -1) {
        return (0);
    } else {
        while (is_num_or_sign(str[i]) == 1) {
            nb = nb + str[i] - 48;
            if (is_num_or_sign(str[i + 1]) == 1)
                nb = nb * 10;
            i++;
        }
        nb = nb * sign;
        if (is_out_of_bound(nb) == 1)
            return (0);
        return (nb);
    }
}
