##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## 
##

SRC	=	main.c	\
		my_putchar.c \
		my_putstr.c \
		get_next_line.c 
		
OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS = -Iinclude

$(NAME): $(OBJ)
	gcc -c $(SRC) -Iinclude 
	ar rc $(NAME) $(OBJ)
	gcc $(NAME) -o mysh

all: $(NAME)

clean:
	rm -f *~
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
