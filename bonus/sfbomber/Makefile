##
## EPITECH PROJECT, 2020
## OOP_indie_studio_2019
## File description:
## Makefile
##

SRC	=	src/main.cpp			\
		src/MainLoop.cpp		\
		src/Game.cpp			\
		src/Player.cpp			\
		src/Animation.cpp		\
		src/SolidWall.cpp		\
		src/Ground.cpp			\
		src/BreakableWall.cpp	\
		src/Bomb.cpp			\
		src/Explosion.cpp		\
		src/Powerup.cpp

CC	=	g++

OBJ	=	$(SRC:.cpp=.o)

NAME	=	mybomber

CPPFLAGS	=	-I./include

LDLIBS	=

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDLIBS) $(LDFLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean	all

.PHONY:	all	clean	fclean	re
