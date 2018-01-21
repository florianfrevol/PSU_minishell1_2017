##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	src/shell.c 		\
		src/basic_commands.c	\
		src/unsetenv.c		\
		src/setenv.c		\
		src/src.c 		\
		src/getnbr.c		\
		src/main.c		\
		src/reduce_shell.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-g -I include/

all: $(NAME)

$(NAME):	$(SRC)
	gcc -o $(NAME) $(SRC) $(CFLAGS) -L./lib/ -lgnl

clean:
	rm -f $(OBJ)
	rm -f *~
fclean: clean
	rm -f $(NAME)

re: fclean all