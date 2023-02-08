##
## EPITECH PROJECT, 2021
## Project Name
## File description:
## my Makefile
##

SRC	= 	src/Comp/PIN/PIN.cpp \
		src/Comp/And/And.cpp \
		src/Comp/Or/Or.cpp \
		src/Comp/Xor/Xor.cpp \
		src/Comp/Invert/Invert.cpp \
		src/Comp/Input/Input.cpp \
		src/Comp/Output/Output.cpp \
		src/parsing/parse.cpp \
		src/Tower/ControlTower.cpp \


OBJ	=	$(SRC:.cpp=.o)

MAIN	=	main.cpp

CPPFLAGS	=	-I ./include

CFLAGS	=	-Wall -Wextra -std=c++20

NFLAGS	=	-lncurses -lmenu

SFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NAME	=	nanotekspice

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(MAIN) $(SRC) $(MY) -o $(NAME) $(CPPFLAGS) $(CFLAGS)

clean:
	rm -rf *~
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf *.a

re: fclean makelib all

unitest: CFLAGS += -lcriterion
unitest:
	gcc -o $(NAME) $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)

debug: CFLAGS += -g3
debug: all

.PHONY: all makelib clean fclean re unitest debug
