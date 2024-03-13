/*
** EPITECH PROJECT, 2023
** get_files_input
** File description:
** Placeholder
*/

#include "../include/my.h"


/*
// \brief Gives the files of the input and their information
//
// \param ac Number of elements in av
// \param av Array containing the paths and/or flags
//
// \return An array of file_t containing the path and stat of each file
*/
int get_files_input(int ac, char **av, input_t *input, int count2)
{
    struct stat *st = malloc(sizeof(struct stat));
    file_t *files = malloc(sizeof(file_t) * (ac - count2));
    int count = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-' && stat(av[i], st) != 0)
            return i;
        if (av[i][0] != '-') {
            files[count].path = malloc(sizeof(char) * (my_strlen(av[i]) + 1));
            my_strcpy(files[count].path, av[i]);
            files[count].hidden = (av[i][0] == '.') ? 1 : 0;
            files[count].st = *st;
            count++;
        }
    }
    files[count].path = NULL;
    input->files_nb = count;
    input->files = files;
    return 0;
}
