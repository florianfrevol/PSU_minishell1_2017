/*
** EPITECH PROJECT, 2017
** gnl.h
** File description:
** 
*/

#ifndef	__LIBGNL__
#define	__LIBGNL__

char *get_next_line(int fd);
char *get_next_line_dbg(int fd);
int my_put_nbr(int nb);
void my_putchar(char c);
char *change_env(char *str);
int my_putstr(char *str);
char *my_revstr(char *str);
int my_strlen(char *str);
int get_nbr(char *str);
int compare(char *str, char *compare);
void print_only_begining(char *str);
int check_if_empty(char *str);
void check_for_commande(char *str, char **tabl, char **env);
int compt_number(char *str);
char **put_setenv(char **env, char *str);
int compt_lign(char **env);
char *find_first_word(char *str);
int check_if_exist(char **env, char *str);
char **check_unsetenv(char **env, char **tabl, char *str);
int nbr_word(char *str);
void print_env(char **env);
char **check_setenv(char **env, char *str, char **tabl);
void check_for_env(char **env, char *str);
int check_word(char *str);
char **child_creation(char **env, char **arg, char *str2);
char **regroup(char *str, char **env, char **tabl);
char **path_cut(char **env);
char **take_all_path(char *path, int nb_arg);
int find_nb_arg(char *path);
void my_puterror(char *str);
char *my_strcat(char *source, char *dest);
char *find_path(char **env);

#endif