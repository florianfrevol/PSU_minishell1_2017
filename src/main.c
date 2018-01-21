/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** 
*/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include "gnl.h"
#include <stdlib.h>

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
		tabl = create_tabl_str(str);
		check_for_env(env, str);
		check_for_commande(str);
		env = check_setenv(env, str);
		env = check_unsetenv(env, tabl, str);
		if (compare(str, "exit") == 2) {
			my_putstr("exit\n");
			return (compt_number(str));
		}
	}
	return (0);
}