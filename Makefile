##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	src.c\
		shell.c\
		getnbr.c\
		basic_commands.c\
		setenv.c\
		unsetenv.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) libgnl.a

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all