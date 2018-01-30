/*
** EPITECH PROJECT, 2017
** getnbr.c
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>
#include "gnl.h"

int get_nbr(char *str)
{
	int i = 0;
	int e = 1;
	int result = 0;

	my_revstr(str);
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			result = result + ((str[i] - 48) * e);
			e = e * 10;
		}
		i ++;
	}
	my_revstr(str);
	return (result);
}

int nbr_word(char *str)
{
	int i = 0;
	int e = 0;

	while (str[i] != '\0') {
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i ++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			i ++;
		e ++;
	}
	return (e);
}

void my_puterror(char *str)
{
	write(2, str, my_strlen(str));
}