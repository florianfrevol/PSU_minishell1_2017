/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** 
*/

#include "get_next_line.h"

static char rec[READ_SIZE + 1];

int my_strlen(char *chain)
{
	int cpt = 0;

	for (cpt = 0; chain[cpt] != '\0'; cpt = cpt + 1){
	}
	return(cpt);
}

int count(char *ligne)
{
	int p = 0;
	int i = 0;

	for (i = 0; rec[i] != '\0'; i = i + 1) {
		if (rec[i] == '\n') {
			return (0);
		}
	}
	while (p <= 50)
		p = p + 1;
	if (p > 20)
		return (1);
}

char *my_str_cat(char *str1, char *str2)
{
	char *str3 = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
	int a = 0;
	int c = 0;

	for (a = 0; str1[a] != '\0'; a = a + 1) {
		str3[c] = str1[a];
		c = c + 1;
	}
	a = 0;
	while (str2[a] != '\0') {
		str3[c] = str2[a];
		c = c + 1;
		a = a + 1;
	}
	str3[c] = '\0';
	return (str3);
}

int compact(char *ligne)
{
	int a = 0;
	int b = 0;
	char *middle = malloc(sizeof(char) * (my_strlen(ligne) + 1));

	for (a = 0; ligne[a] != '\n'; a = a + 1)
		middle[a] = ligne[a];
	middle[a] = '\0';
	if(ligne[a] == '\n')
		a = a + 1;
	for (b = 0; ligne[a] != '\0'; b = b + 1) {
		rec[b] = ligne[a];
		if (a > -1)
			a++;
	}
	middle[a+1] = '\0';
	rec[b+1] = '\0';
	return (middle);
}

char *get_next_line (int fd)
{	
	char *buffer = malloc(sizeof(char)*(READ_SIZE + 1));
	int cpt = 0;
	char *ligne = rec;

	if (fd == -1) 
		return (NULL);
	cpt = read(fd, buffer, READ_SIZE);
	buffer[cpt+1] = '\0';
	ligne = my_str_cat(ligne, buffer);
	while (count(ligne) && cpt == READ_SIZE) {
		cpt = read(fd, buffer, READ_SIZE);
		buffer[cpt] = '\0';
		ligne = my_str_cat(ligne, buffer);
	}
	if (fd < 0)
		return (NULL);
	ligne = compact(ligne);
	return (ligne);
}
