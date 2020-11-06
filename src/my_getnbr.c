/*
** ETNA PROJECT, 02/11/2020 by yu_t
** [...]
** File description:
**      [...]
*/

#include "my_crd.h"

int is_alpha(const char c)
{
   if ((c >= 'a' && c <= 'z') ||
       (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0; 
}

int is_num(const char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int get_sign(const char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] && (is_num(str[i]) == 0)) {
        if (str[i] == '-') {
            count++;
        }
        i++;
    }
    return (count % 2);
}

int check_char(const char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == '-' || str[i] == '+')
            i++;
        if (is_alpha(str[i]) == 1 && ((is_num(str[i + 1]) == 1) ||
            (str[i - 1] == '-') || (str[i - 1] == '+')) && str[i + 1])
            return 1;
        i++;
    }
    return 0;
}

unsigned int my_getnbr(char *str)
{
    int i = 0;
    unsigned int number = 0;
    int sign = get_sign(str);
    int limit = 0;

    if (check_char(str) == 1)
        return 0;
    while (str[i]) {
        if ((number >= 429496729 && (str[i] - '0' > 5) && (sign == 0)))
            return 0;
        if (is_num(str[i]) == 1) {
            number += str[i] - '0';
            limit++;
            if (is_num(str[i + 1]) == 1)
                number *= 10;
        }
        i++;
    }
    if (sign == 1)
        number *= -1;
    return (number);
}
