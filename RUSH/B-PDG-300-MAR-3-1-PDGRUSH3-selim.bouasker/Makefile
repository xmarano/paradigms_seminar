##
## EPITECH PROJECT, 2025
## B-PDG-300-MAR-3-1
## File description:
## Makefile
##

NAME	=	MyGKrellm

FLAGS   =   -std=c++20 -Wall -Wextra -Werror -lncurses

all:
	g++ -o $(NAME) *.cpp $(FLAGS)
	cd ./SFML && g++ -std=c++11 -o sfmldisplay sfmldisplay.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/opt/homebrew/Cellar/csfml/2.6.1_1/include/ -L/opt/homebrew/Cellar/csfml/2.6.1_1/lib && cd ..
	rm -f *.o

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
