/*
** EPITECH PROJECT, 2017
** minishell.h
** File description:
** 
*/

#include "get_next_line.h"

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char *str);
char *my_revstr(char *str);
int my_strlen(char *str);
char *re_alloc(char *chaine, int compt, int c);
void init(s_t *s, int i);
int reduce(s_t *s, int m, char *str);
int end(char *str);
char *get_next_line(int fd);