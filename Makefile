##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	get_next_line.c\
		src.c\
		shell.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all