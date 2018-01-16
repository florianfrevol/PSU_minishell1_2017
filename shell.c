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
	if (str[0] == 'e' && str[1] == 'n' && str[2] == 'v') {
		print_env(env);
	}
}

int main(int argc, char **argv, char **env)
{
	char *str;

	while (1) {
		my_putstr("$>");
		str = get_next_line(0);
		check_for_env(env, str);
		/*while (env[i] != 0) {
			my_putstr(env[i]);
			my_putchar('\n');
			i ++;
		}*/
	}

	return (0);
}