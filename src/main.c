/*
** EPITECH PROJECT, 2017
** main.c
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

char *my_strcat(char *source, char *dest)
{
	int total = (my_strlen(source) + my_strlen(dest) + 1);
	char *ret = malloc(sizeof(char) * total);
	int i = 0;
	int w = 0;

	while (dest[i] != '\0') {
		ret[w] = dest[i];
		i = i + 1;
		w = w + 1;
	}
	i = 0;
	while (source[i] != '\0') {
		ret[w] = source[i];
		i = i + 1;
		w = w + 1;
	}
	ret[w] = '\0';
	return (ret);
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

char *find_path(char **env)
{
	int i = 0;

	while (env[i] != NULL) {
		if (compare(env[i], "PATH=") == 2)
			return (env[i]);
		i = i + 1;
	}
	return (NULL);
}

void my_prompt(char **env)
{
	int i = 0;
	int e = 4;

	while (compare(env[i], "PWD=") != 2)
		i ++;
	while (env[i][e] != '\0') {
		my_putchar(env[i][e]);
		e ++;
	}
	my_putchar(' ');
}

int main(int argc, char **argv, char **env)
{
	char *str;
	char **tabl;

	while (1) {
		my_prompt(env);
		str = get_next_line(0);
		if (str == NULL) {
			my_putchar('\n');
			return (0);
		}
		tabl = create_tabl_str(str);
		env = child_creation(env, tabl, str);
		if (compare(str, "exit") == 2) {
			my_putstr("exit\n");
			return (compt_number(str));
		}
	}
	return (0);
}