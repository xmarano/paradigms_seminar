##
## EPITECH PROJECT, 2025
## B-PDG-300-MAR-3-1
## File description:
## Makefile
##

SRC		=	$(wildcard *.c)

NAME	=	a.out

OBJ		=	$(SRC:.c=.o)

FLAGS   =   -std=gnu17 -Wall -Wextra -L. -lstring

all:	$(OBJ)
	ar rc libstring.a $(OBJ)
	rm -f *.o

test : 	$(NAME)

$(NAME):	$(OBJ)
	ar rc libstring.a $(OBJ)
	gcc -o $(NAME) $(OBJ) $(FLAGS)
	rm -f *.o

clean:
	rm -f *.o
	rm -f libstring.a

fclean:	clean
	rm -f $(NAME)

re:	fclean all
