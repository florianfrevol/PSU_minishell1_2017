/*
** EPITECH PROJECT, 2017
** reduce_shell.c
** File description:
** 
*/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include "gnl.h"
#include <stdlib.h>

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
			env[i] = change_env(str);
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
		print_env(env);
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