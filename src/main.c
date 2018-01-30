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

void my_puterror(char *str)
{
	write(2, str, my_strlen(str));
}

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

char *find_path(char **envp)
{
	int i = 0;

	while (envp[i] != NULL) {
		if (compare(envp[i], "PATH=") == 2)
			return (envp[i]);
		i = i + 1;
	}
	return (NULL);
}

int find_nb_arg(char *path)
{
	int i = 0;
	int w = 0;

	while (path[i] != '\0') {
		if (path[i] == ':')
			w = w + 1;
		i = i + 1;
	}
	return (w + 1);
}

char **take_all_path(char *path, int nb_arg)
{
	char **result = malloc(sizeof(char *) * nb_arg);
	int i = 0;
	int w = 0;
	int z = 0;
	while (i < nb_arg) 
		result[i ++] = malloc(sizeof(char) * my_strlen(path));
	i = 5;
	while (path[i] != '\0') {
		if (path[i] == ':') {
			w = w + 1;
			z = 0;
			i = i + 1;
		} else {
			result[w][z] = path[i];
			i = i + 1;
			z = z + 1;
		}
	}
	return (result);
}

char **path_cut(char **envp)
{
	char *path = find_path(envp);
	int nb_arg = find_nb_arg(path);
	char **multi = take_all_path(path, nb_arg);

	return (multi);
}

void child_creation(char **envp, char **arg)
{
	pid_t child_pid = fork();
	int status = 0;
	char **multi = path_cut(envp);
	int i = 0;
	char *str;

	if (child_pid == 0) {
		while (multi[i] != NULL) {
			str = my_strcat("/", multi[i]);
			execve(my_strcat(arg[0], str), arg, envp);
			i = i + 1;
		}
		execve(my_strcat(arg[0], "./"), arg, envp);
		execve(my_strcat(arg[0], "/"), arg, envp);
		my_puterror(arg[0]);
		my_puterror(": Command not found.\n");
	}
	else {
		waitpid(child_pid, &status, 0);
		if (WIFSIGNALED(status) == 1 && WCOREDUMP(status) == 128)
			my_puterror("Segmentation fault (core dumped)\n");
	}
}

char *path_check(char **env)
{
	int i = 0;
	char *str;
	int e = 0;

	while (compare(env[i], "PATH=") != 2) {
		i ++;
	}
	e = 5;
	str = malloc(sizeof(char) * my_strlen(env[i]) + 1);
	while (env[i][e] != '\0') {
		str[e - 5] = env[i][e];
		e ++;
	}
	str[e - 5] = '\0';
	return (str);
}


int main(int argc, char **argv, char **env)
{
	char *str;
	char **tabl;

	while (1) {
		my_putstr("$> ");
		str = get_next_line(0);
		if (str == NULL) {
			my_putchar('\n');
			return (0);
		}
		tabl = create_tabl_str(str);
		//char *path = path_check(env);
		//my_putstr(path);
		if (compare(str, "ls") == 2 || compare(str, "pwd") == 2)
			child_creation(env, tabl);
		check_for_env(env, str);
		check_for_commande(str, tabl, env);
		env = check_setenv(env, str);
		env = check_unsetenv(env, tabl, str);
		if (compare(str, "exit") == 2) {
			my_putstr("exit\n");
			return (compt_number(str));
		}
	}
	return (0);
}
