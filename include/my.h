/*
** EPITECH PROJECT, 2023
** myh
** File description:
** Placeholder
*/

#ifndef MY_H_
    #define MY_H_
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

typedef struct file {
    char *path;
    int hidden;
    struct stat st;
} file_t;
typedef struct input {
    unsigned char flags;
    file_t *files;
    int files_nb;
} input_t;
void my_putnbr(long nb);
int do_flag_l(struct dirent **tab, unsigned char flags, char *path);
void give_path(char *path, char *name, struct stat *st);
int get_input(int ac, char **av, input_t *in);
void sort_tab(struct dirent ***tab, unsigned char flags, char *path);
char *my_strcat(char *dest, char const *src);
int get_flags(int ac, char **av, input_t *input, int *count);
int get_files_input(int ac, char **av, input_t *input, int count);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int do_no_such_flag(int c);
int do_no_such_file(char **av, int file);
#endif
