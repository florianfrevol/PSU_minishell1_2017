/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** minishell
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int recupath (char **path)
{
	int cpt = 0;
	int cpt2 = 5;
	char *new;

	while (path[cpt] != 0) {
		if (path[cpt][0] == 'P' && path[cpt][3] == 'H') {
			while (path[cpt][cpt2] != 0) {
				new[cpt2] = path[cpt][cpt2];
				cpt2 = cpt2 + 1;				
			}
		}
		cpt++;
	}
	return (new);
}

int put (char **c)
{
	int cpt = 0;

	while (c[cpt] != 0) {
		my_putstr(c[cpt]);
		my_putchar('\n');
		cpt = cpt + 1;
	}
}

int check (char *str, char **env)
{
	int i = 0;

	if (str[0] == 'e' && str[1] == 'n' && str[2] == 'v' && str[3] == NULL)
		put(env);
	if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && str[3] == 't' && str[4] == NULL)
		return (1);
}

int main (int ac, char **av, char **env)
{
	char *str;
	char *path[200];
	char *commande = "ls";
	pid_t childpid;
	int i = 0;	

	//childpid = fork();	
	while (1) {
		getcwd(path, 199);
		my_putstr(path);
		my_putstr("$>");
		str = get_next_line (0);		
		i = check(str, env);
		execve(path, commande);
		free(str);
		if (i == 1)
			return 0;
	}	
}
