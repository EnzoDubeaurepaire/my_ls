/*
** EPITECH PROJECT, 2023
** get_input
** File description:
** Placeholder
*/

#include "../include/my.h"

int get_files_nb(input_t *input)
{
    int i = 0;

    for (; input->files[i].path != NULL; i++);
    return i - 1;
}

int get_input(int ac, char **av, input_t *in)
{
    input_t *input = malloc(sizeof(input_t));
    int flag;
    int file;
    int count = 0;

    flag = get_flags(ac, av, input, &count);
    if (flag != -1)
        return do_no_such_flag(flag);
    file = get_files_input(ac, av, input, count);
    if (file != 0)
        return do_no_such_file(av, file);
    *in = *input;
    free(input);
    return 0;
}
