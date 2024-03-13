/*
** EPITECH PROJECT, 2023
** lflag
** File description:
** Placeholder
*/

#include "../include/my.h"

static void do_total(struct dirent **tab, unsigned char flags, char *path)
{
    struct stat st;
    long int tot = 0;
    char c;

    write(1, "total ", 6);
    for (int i = 0; tab[i]; i++) {
        give_path(path, tab[i]->d_name, &st);
        tot += st.st_blocks;
    }
    tot /= 2;
    my_putnbr(tot);
    write(1, "\n", 1);
}

static char get_type(struct stat *buf)
{
    char c = 0;

    c = S_ISREG(buf->st_mode) ? '-' : c;
    c = S_ISDIR(buf->st_mode) ? 'd' : c;
    c = S_ISCHR(buf->st_mode) ? 'c' : c;
    c = S_ISBLK(buf->st_mode) ? 'b' : c;
    c = S_ISFIFO(buf->st_mode) ? 'p' : c;
    c = S_ISLNK(buf->st_mode) ? 'l' : c;
    c = S_ISSOCK(buf->st_mode) ? 's' : c;
    return c;
}

void do_rights2(struct stat *st)
{
    if ((st->st_mode & S_IWGRP))
        write(1, "w", 1);
    if (!(st->st_mode & S_IWGRP))
        write(1, "-", 1);
    if ((st->st_mode & S_IXGRP))
        write(1, "x", 1);
    if (!(st->st_mode & S_IXGRP))
        write(1, "-", 1);
    if ((st->st_mode & S_IROTH))
        write(1, "r", 1);
    if (!(st->st_mode & S_IROTH))
        write(1, "-", 1);
    if ((st->st_mode & S_IWOTH))
        write(1, "r", 1);
    if (!(st->st_mode & S_IWOTH))
        write(1, "-", 1);
    if ((st->st_mode & S_IXOTH))
        write(1, "r", 1);
    if (!(st->st_mode & S_IXOTH))
        write(1, "-", 1);
}

void do_rights(struct stat *st)
{
    char type = get_type(st);

    write(1, &type, 1);
    if ((st->st_mode & S_IRUSR))
        write(1, "r", 1);
    if (!(st->st_mode & S_IRUSR))
        write(1, "-", 1);
    if ((st->st_mode & S_IWUSR))
        write(1, "w", 1);
    if (!(st->st_mode & S_IWUSR))
        write(1, "-", 1);
    if ((st->st_mode & S_IXUSR))
        write(1, "x", 1);
    if (!(st->st_mode & S_IXUSR))
        write(1, "-", 1);
    if ((st->st_mode & S_IRGRP))
        write(1, "r", 1);
    if (!(st->st_mode & S_IRGRP))
        write(1, "-", 1);
    do_rights2(st);
}

void do_uid(struct stat *st)
{
    struct passwd *pwuid;
    struct group *gruid;

    write(1, " ", 1);
    pwuid = getpwuid(st->st_uid);
    write(1, pwuid->pw_name, my_strlen(pwuid->pw_name));
    gruid = getgrgid(st->st_gid);
    write(1, " ", 1);
    write(1, gruid->gr_name, my_strlen(gruid->gr_name));
    write(1, " ", 1);
}

void do_time(struct stat *st)
{
    long int time = st->st_mtim.tv_sec;
    char *ct = ctime(&time);

    write(1, " ", 1);
    write(1, ct + 4, my_strlen(ct) - 13);
    write(1, " ", 1);
}

int do_flag_l(struct dirent **tab, unsigned char flags, char *path)
{
    struct stat st;

    if ((flags & 16) != 16)
        do_total(tab, flags, path);
    for (int i = 0; tab[i]; i++) {
        if (!(tab[i]->d_name[0] == '.' && (flags & 1) != 1)) {
            give_path(path, tab[i]->d_name, &st);
            do_rights(&st);
            write(1, ". ", 2);
            my_putnbr((long) st.st_nlink);
            do_uid(&st);
            my_putnbr(st.st_size);
            do_time(&st);
            write(1, tab[i]->d_name, my_strlen(tab[i]->d_name));
            write(1, "\n", 1);
        }
    }
    return 0;
}
