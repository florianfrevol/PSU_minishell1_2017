/*
** EPITECH PROJECT, 2017
** shell.c
** File description:
** 
*/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include "minishell.h"
#include "gnl.h"
#include <stdlib.h>

void print_env(char **env)
{
	int i = 0;

	while (env[i] != 0) {
		my_putstr(env[i]);
		my_putchar('\n');
		i ++;
	}
}

void check_for_env(char **env, char *str)
{
	if (compare(str, "env") == 2) {
		print_env(env);
	}
}

int check_word(char *str)
{
	int i = 0;
	int e = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i ++;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	if (str[i] == '\0')
		return (3);
	return (2);
}

char *reduce_change_env(char *str, int i)
{
	char *new = malloc(sizeof(char) * my_strlen(str) + 1);
	int e = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t') {
		new[e] = str[i];
		i ++;
		e ++;
	}
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	new[e] = '=';
	e ++;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t') {
		new[e] = str[i];
		i ++;
		e ++;
	}
	new[e] = '\0';
	return (new);
}

char *change_env(char *str, char *first_word)
{
	char *new = malloc(sizeof(char) * my_strlen(str) + 1);
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i] != ' ' && str[i] != '\t')
		i ++;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	new = reduce_change_env(str, i);
	return (new);
}

char **reduce_put_env(char **env, char *str)
{
	int i = 0;
	int e = 0;
	int check = 0;
	char *first_word = find_first_word(str);

	while (env[i] != 0) {
		e = 0;
		check = 0;
		while (first_word[e] != '\0') {
			if (first_word[e] == env[i][e])
				check ++;
			e ++;
		}
		if (check == my_strlen(first_word)) {
			env[i] = change_env(str, first_word);
			return (env);
		}
		i ++;
	}
	return (env);
}

char **put_env(char **env, char *str)
{
	if (compare(str, "setenv") == 2)
		env = reduce_put_env(env, str);
	return (env);
}

char **check_setenv(char **env, char *str)
{
	char **new_env = put_setenv(env, str);
	char **env_if_exist = put_env(env, str);

	if (compare(str, "setenv") == 2 && (check_word(str) == 2 ||
		check_word(str) == 3) && check_if_exist(env, str) == 2) {
		return (env);
	}
	if (compare(str, "setenv") == 2 && check_word(str) == 2) {
		return (new_env);
	}
	if (compare(str, "setenv") == 2 && check_word(str) == 3) {
		print_env(env);
	}
	return (env);
}

char *find_first_word(char *str)
{
	int i = 0;
	int e = 0;
	char *new_char = malloc(sizeof(char) * my_strlen(str) + 1);

	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i] != ' ' && str[i] && '\t')
		i ++;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i] != ' ' && str[i] && '\t') {
		new_char[e] = str[i];
		e ++;
		i ++;
	}
	new_char[e] = '\0';
	return (new_char);
}

int check_if_exist(char **env, char *str)
{
	int i = 0;
	int e = 0;
	int check = 0;
	char *first_word = find_first_word(str);

	while (env[i] != 0) {
		e = 0;
		check = 0;
		while (first_word[e] != '\0') {
			if (first_word[e] == env[i][e])
				check ++;
			e ++;
		}
		if (check == my_strlen(first_word)) {
			return (2);
		}
		i ++;
	}
	return (3);
}

int turn_spaces(char *str, int i)
{
	while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
		i ++;
	return (i);
}

int turn_words(char *str, int i)
{
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i ++;
	return (i);
}

int nbr_word(char *str)
{
	int i = 0;
	int e = 0;

	while (str[i] != '\0') {
		i = turn_spaces(str, i);
		i = turn_words(str, i);
		e ++;
	}
	return (e);
}

char **create_tabl_str(char *str)
{
	int i = 0;
	int e = 0;
	int k = 0;
	char **tabl = malloc(sizeof(char *) * nbr_word(str) + 1);

	while (str[i] != '\0') {
		e = 0;
		tabl[k] = malloc(sizeof(char) * my_strlen(str) + 1);
		while (str[i] == ' ' || str[i] == '\t')
			i ++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t') {
			tabl[k][e] = str[i];
			e ++;
			i ++;
		}
		tabl[k][e] = '\0';
		k ++;
	}
	return (tabl);
}

int main(int argc, char **argv, char **env)
{
	char *str;
	char **tabl;

	while (1) {
		my_putstr("$> ");
		str = get_next_line(0);
		if (str == NULL)
			return(0);
		tabl = create_tabl_str(str);
		check_for_env(env, str);
		check_for_commande(str);
		env = check_unsetenv(env, tabl, str);
		env = check_setenv(env, str);
		if (compare(str, "exit") == 2) {
			my_putstr("exit\n");
			return (compt_number(str));
		}
	}
	return (0);
}