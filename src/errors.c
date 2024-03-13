/*
** EPITECH PROJECT, 2023
** errors
** File description:
** Placeholder
*/

#include "../include/my.h"

int do_no_such_flag(int c)
{
    write(2, "my_ls: invalid option -- '", 26);
    write(2, &c, 1);
    write(2, "'\n", 2);
    return 84;
}

int do_no_such_file(char **av, int file)
{
    write(2, "my_ls: cannot access '", 22);
    write(2, av[file], my_strlen(av[file]));
    write(2, "' No such file or directory\n", 28);
    return 84;
}
