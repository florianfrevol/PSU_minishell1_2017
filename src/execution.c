/*
** EPITECH PROJECT, 2018
** execve
** File description:
** s
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include "gnl.h"

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

char **path_cut(char **env)
{
	char *path = find_path(env);
	int nb_arg = find_nb_arg(path);
	char **multi = take_all_path(path, nb_arg);

	return (multi);
}

char **regroup(char *str, char **env, char **tabl)
{
	check_for_env(env, str);
	check_for_commande(str, tabl, env);
	env = check_setenv(env, str);
	env = check_unsetenv(env, tabl, str);
	return (env);
}

char **child_creation(char **env, char **arg, char *str2)
{
	pid_t child_pid = fork();
	int status = 0;
	char **multi = path_cut(env);
	int i = 0;
	char *str;

	if (child_pid == 0) {
		while (multi[i] != NULL) {
			str = my_strcat("/", multi[i]);
			execve(my_strcat(arg[0], str), arg, env);
			i = i + 1;
		}
		execve(my_strcat(arg[0], "./"), arg, env);
		execve(my_strcat(arg[0], "/"), arg, env);
		my_puterror(arg[0]);
		my_puterror(": Command not found.\n");
	} else {
		waitpid(child_pid, &status, 0);
		if (WIFSIGNALED(status) == 1)
			env = regroup(str2, env, arg);
	}
	return (env);
}