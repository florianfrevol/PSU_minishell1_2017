/*
** EPITECH PROJECT, 2017
** setenv.c
** File description:
** 
*/

#include "gnl.h"
#include <stdlib.h>

int compt_lign(char **env)
{
	int i = 0;

	while (env[i] != 0)
		i ++;
	return (i);
}

char *create_new(char *str, int i)
{
	int e = 0;
	char *new = malloc(sizeof(char) * my_strlen(str) + 1);

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

char *create_new_line(char *str)
{
	int i = 0;
	char *new = malloc(sizeof(char) * my_strlen(str) + 1);

	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	while (str[i] != ' ' && str[i] != '\t')
		i ++;
	while (str[i] == ' ' || str[i] == '\t')
		i ++;
	new = create_new(str, i);
	return (new);
}

char **put_setenv(char **env, char *str)
{
	int i = 0;
	int e = 0;
	char **cpy = malloc(sizeof(char *) * (compt_lign(env) + 1));

	while (env[i] != 0) {
		e = 0;
		cpy[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
		while (env[i][e] != '\0') {
			cpy[i][e] = env[i][e];
			e ++;
		}
		cpy[i][e] = '\0';
		i ++;
	}
	cpy[i] = create_new_line(str);
	cpy[i + 1] = 0;
	return (cpy);
}