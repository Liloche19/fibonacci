SRC	=	src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	fibonacci

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
