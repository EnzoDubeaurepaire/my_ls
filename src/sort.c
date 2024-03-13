/*
** EPITECH PROJECT, 2023
** sort
** File description:
** Placeholder
*/

#include "../include/my.h"

void give_path(char *path, char *name, struct stat *st)
{
    char *tmp = malloc(sizeof(char) * 1024);

    my_strcpy(tmp, path);
    my_strcat(tmp, "/");
    my_strcat(tmp, name);
    stat(tmp, st);
    free(tmp);
}

void time_sort(struct dirent ***tab, char *path)
{
    struct stat st;
    long int max;
    int max_i;
    struct dirent *tmp;

    for (int i = 0; (*tab)[i]; i++) {
        give_path(path, (*tab)[i]->d_name, &st);
        max = st.st_mtim.tv_sec;
        max_i = i;
        for (int j = i + 1; (*tab)[j]; j++) {
            give_path(path, (*tab)[j]->d_name, &st);
            max_i = (st.st_mtim.tv_sec > max) ? j : max_i;
            max = (st.st_mtim.tv_sec > max) ? st.st_mtim.tv_sec : max;
        }
        tmp = (*tab)[i];
        (*tab)[i] = (*tab)[max_i];
        (*tab)[max_i] = tmp;
    }
}

void reverse_sort(struct dirent ***tab)
{
    struct dirent *tmp;
    int j = 0;
    int k;

    for (; (*tab)[j] != NULL; j++);
    j--;
    k = j / 2;
    for (int i = 0; i != k; i++) {
        tmp = (*tab)[j];
        (*tab)[j] = (*tab)[i];
        (*tab)[i] = tmp;
        j--;
    }
}

void sort_tab(struct dirent ***tab, unsigned char flags, char *path)
{
    if ((flags & 32) == 32)
        time_sort(tab, path);
    if ((flags & 4) == 4)
        reverse_sort(tab);
}
