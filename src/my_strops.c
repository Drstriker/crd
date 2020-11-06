/*
** ETNA PROJECT, 03/11/2020 by yu_t
** [...]
** File description:
**      [...]
*/

#include "my_crd.h"

int     my_strlen(char *str)
{
    int	i = 0;
    
    while (str[i])
        i++;
    return (i);
}

char	*my_strcpy(char *dest, char *src)
{
    int	i = 0;
    
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    *my_strdup(char *src)
{
    char *dest = NULL;

    if (src != NULL) {
        dest = malloc((my_strlen(src) * sizeof(char)) + 1);
        if (dest != NULL) {
            my_strcpy(dest, src);
        }
    }
    return (dest);
}

int     my_strcmp(char *s1, char *s2)
{
    int	i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0')
	          return (0);
        i++;
      }
    return (s1[i] - s2[i]);
}

int     my_strisnum(char *str)
{
    int i = 0;
    
    if (!str)
        return 0;
    while (is_num(str[i]) && str[i]) {
        if (!is_num(str[i]))
            return 0;
        i++;
    }
    return 1;
}