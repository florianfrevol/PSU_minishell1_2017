/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** 
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "minishell.h"

char *re_alloc(char *chaine, int compt, int c)
{
	char *str2 = malloc(sizeof(char) * READ_SIZE * (compt + 1) + 1 + c);
	int p = 0;

	while (chaine[p] != '\0') {
		str2[p] = chaine[p];
		p = p + 1;
	}
	str2[p] = '\0';
	return (str2);
}

void init(s_t *s, int i)
{
	s->chaine = malloc(sizeof(char) * READ_SIZE * READ_SIZE + 1);
	s->e = 0;
	s->k = 0;
	s->p = 0;
	s->b = i;
}

int reduce_again(char *str, int i, s_t *s, int m)
{
	while (i != m) {
		if (str[i] == '\n') {
			i ++;
			s->chaine[s->e] = '\0';
			return (2);
		}
		s->chaine[s->e] = str[i];
		s->e ++;
		i ++;
	}
	return (3);
}

char *get_next_line(int fd)
{
	static char str[READ_SIZE + 1];
	static int i = 0;
	static int m = 0;
	static int compt = 0;
	s_t s;

	init(&s, i);
	while (1) {
		i = 0;
		m = read(fd, str, READ_SIZE);
		if (reduce_again(str, i, &s, m) == 2)
			return (s.chaine);
		s.chaine[s.e] = '\0';
		compt ++;
		s.chaine = re_alloc(s.chaine, compt, s.p);
	}
}