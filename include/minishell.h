/*
** EPITECH PROJECT, 2017
** minishell.h
** File description:
** 
*/

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char *str);
char *my_revstr(char *str);
int my_strlen(char *str);
int get_nbr(char *str);
int compare(char *str, char *compare);
void print_only_begining(char *str);
int check_if_empty(char *str);
void check_for_commande(char *str);
int compt_number(char *str);
char **put_setenv(char **env, char *str);
int compt_lign(char **env);
char *find_first_word(char *str);
int check_if_exist(char **env, char *str);
char **check_unsetenv(char **env, char **tabl, char *str);
int nbr_word(char *str);
void print_env(char **env);

typedef struct s
{
	char **new_env;
} s_t;