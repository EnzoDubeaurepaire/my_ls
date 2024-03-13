/*
** EPITECH PROJECT, 2023
** errors
** File description:
** Placeholder
*/

#include "../include/my.h"

int write_dir(struct dirent **tab, unsigned char flags, char *path)
{
    if ((flags & 2) == 2)
        return do_flag_l(tab, flags, path);
    for (int i = 0; tab[i] != NULL; i++) {
        if (!(tab[i]->d_name[0] == '.' && ((flags & 1) != 1 ||
            tab[i]->d_name[1] == '\0' || tab[i]->d_name[1] == '.'))) {
            write(1, tab[i]->d_name, my_strlen(tab[i]->d_name));
            write(1, "\n", 1);
        }
    }
    return 0;
}

struct dirent **get_tab(DIR *dir, DIR *dir2, unsigned char flags, char *path)
{
    struct dirent **tab;
    struct dirent *files = readdir(dir);
    int i = 0;
    int j = 0;

    for (; files != NULL; files = readdir(dir))
        i++;
    tab = malloc(sizeof(struct dirent) * i);
    files = readdir(dir2);
    for (; files != NULL; files = readdir(dir2)) {
        tab[j] = files;
        j++;
    }
    tab[j] = NULL;
    sort_tab(&tab, flags, path);
    return tab;
}

void write_path(char **path, char *name)
{
    my_strcat(*path, "/\0");
    my_strcat(*path, name);
    write(1, "\n", 1);
    write(1, *path, my_strlen(*path));
    write(1, ":\n", 2);
}

int my_ls(char *path, unsigned char flags)
{
    DIR *dir = opendir(path);
    DIR *dir2 = opendir(path);
    int len = my_strlen(path);
    struct dirent **tab;

    if (!dir)
        return 84;
    tab = get_tab(dir, dir2, flags, path);
    write_dir(tab, flags, path);
    for (int i = 0; tab[i] != NULL && (flags & 8) == 8; i++)
        if (tab[i]->d_type == DT_DIR && !(tab[i]->d_name[0] == '.' &&
            ((flags & 1) != 1 || tab[i]->d_name[1] == '\0' ||
            tab[i]->d_name[1] == '.'))) {
            write_path(&path, tab[i]->d_name);
            my_ls(path, flags);
            path[len] = '\0';
        }
    return 0;
}

int main(int ac, char **av)
{
    input_t *input = malloc(sizeof(input_t));
    int ret = get_input(ac, av, input);
    char *i_path = malloc(sizeof(char) * 2);

    i_path[0] = '.';
    i_path[1] = '\0';
    if (ret != 0)
        return 84;
    if ((input->flags & 8) == 8 && input->files[0].path) {
        write(1, input->files[0].path, my_strlen(input->files[0].path));
        write(1, ":\n", 2);
    }
    if ((input->flags & 8) == 8 && !input->files[0].path)
        write(1, ".:\n", 3);
    if (!input->files[0].path)
        ret = my_ls(i_path, input->flags);
    for (int i = 0; input->files[i].path != NULL; i++)
        ret = my_ls(input->files[i].path, input->flags);
    return ret;
}
