/*
** EPITECH PROJECT, 2017
** basic_commands.c
** File description:
** 
*/

#include "minishell.h"

int compare(char *str, char *compare)
{
	int i = 0;
	int e = 0;

	while (compare[i] != '\0') {
		if (compare[i] == str[i])
			e ++;
		i ++;
	}
	if (e == my_strlen(compare) && (str[i] == ' ' || str[i] == '\0' || str[i] == '\n'))
		return (2);
	else
		return (3);
}

void print_only_begining(char *str)
{
	int i = 0;

	while (str[i] == ' ')
		i ++;
	while (str[i] != '\0' && str[i] != ' ') {
		my_putchar(str[i]);
		i ++;
	}
	my_putstr(": Command not found.");
}

int check_if_empty(char *str)
{
	int i = 0;
	int e = 0;

	while (str[i] != '\0' && str[i] != '\n') {
		if (str[i] != ' ' && str[i] != '\n' &&
		str[i] != '\0' && str[i] != '\t')
			e ++;
		i ++;
	}
	if (e != 0)
		return (2);
	else
		return (3);
}

void check_for_commande(char *str)
{
	if (check_if_empty(str) == 2) {
		if ((compare(str, "exit") + compare(str, "env") +
		compare(str, "setenv") + compare(str, "unsetenv")) == 12) {
			print_only_begining(str);
			my_putchar('\n');
		}
	}
}

int compt_number(char *str)
{
	int nbr = get_nbr(str);

	while (nbr > 255) {
		nbr = nbr - 256;
	}
	return (nbr);
}