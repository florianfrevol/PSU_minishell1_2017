/*
** EPITECH PROJECT, 2017
** unsetenv.c
** File description:
** 
*/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include "minishell.h"
#include "lib/gnl.h"
#include <stdlib.h>

int find_i(char **env, char *str)
{
	int i = 0;
	int e = 0;
	int check = 0;

	while (env[i] != 0) {
		e = 0;
		check = 0;
		while (str[e] != '\0') {
			if (str[e] == env[i][e])
				check ++;
			e ++;
		}
		if (check == my_strlen(str)) {
			return (i);
		}
		i ++;
	}
}

char **delate_lign(char **env, char *str)
{
	int i = 0;
	int e = 0;
	int k = 0;
	char **new_env = malloc(sizeof(char *) * (compt_lign(env) + 1));

	while (env[k + i] != 0) {
		e = 0;
		if (i == find_i(env, str)) {
			k ++;
		}
		new_env[i] = malloc(sizeof(char) * my_strlen(env[k + i]) + 1);
		while (env[k + i][e] != '\0') {
			new_env[i][e] = env[k + i][e];
			e ++;
		}
		new_env[i][e] = '\0';
		i ++;
	}
	new_env[i + 1] = 0;
	return (new_env);
}

int check_unsetenv_possible(char **env, char *str)
{
	int i = 0;
	int e = 0;
	int check = 0;

	while (env[i] != 0) {
		e = 0;
		check = 0;
		while (str[e] != '\0') {
			if (str[e] == env[i][e])
				check ++;
			e ++;
		}
		if (check == my_strlen(str)) {
			return (2);
		}
		i ++;
	}
	return (3);
}

char **check_unsetenv(char **env, char **tabl, char *str)
{
	int i = 1;
	char **new_env = malloc(sizeof(char *) * (compt_lign(env) + 1));
	int k = 0;

	if (compare(str, "unsetenv") == 2) {
		while (i != nbr_word(str)) {
			if (k == 0 && check_unsetenv_possible(env, tabl[i]) == 2) {
				new_env = delate_lign(env, tabl[i]);
				k ++;
			} else if (k != 0 && check_unsetenv_possible(new_env, tabl[i]) == 2)
				new_env = delate_lign(new_env, tabl[i]);
			i ++;
		}
		if (k != 0)
			return (new_env);
	}
	return (env);
}