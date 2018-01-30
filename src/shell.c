/*
** EPITECH PROJECT, 2017
** shell.c
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include "gnl.h"

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

char *change_env(char *str)
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