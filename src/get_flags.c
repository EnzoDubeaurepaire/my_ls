/*
** EPITECH PROJECT, 2023
** get_flags
** File description:
** Placeholder
*/

#include "../include/my.h"

int is_flag(char c)
{
    return (c == 'a' || c == 'l' || c == 'r' ||
        c == 'R' || c == 'd' || c == 't');
}

int search_flags(char *str, input_t *input)
{
    unsigned char tmp = 0;

    for (int i = 1; str[i] != '\0'; i++) {
        if (!is_flag(str[i]))
            return (int)str[i];
        if (str[i] == 'a' && (tmp & 1) == 0)
            tmp += 1;
        if (str[i] == 'l' && (tmp & 2) == 0)
            tmp += 2;
        if (str[i] == 'r' && (tmp & 4) == 0)
            tmp += 4;
        if (str[i] == 'R' && (tmp & 8) == 0)
            tmp += 8;
        if (str[i] == 'd' && (tmp & 16) == 0)
            tmp += 16;
        if (str[i] == 't' && (tmp & 32) == 0)
            tmp += 32;
    }
    input->flags = tmp | input->flags;
    return -1;
}

int get_flags(int ac, char **av, input_t *input, int *count)
{
    int ret = -1;
    int tmp;

    for (; ac > 1; ac--)
        if (av[ac - 1][0] == '-') {
            tmp = search_flags(av[ac - 1], input);
            ret = (ret == -1) ? tmp : ret;
            *count++;
        }
    return ret;
}
