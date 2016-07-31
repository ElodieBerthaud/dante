##
## Makefile for  in /home/bertha_e/rendu/Initiation_IA/dante
## 
## Made by Berthaud Elodie
## Login   <bertha_e@epitech.net>
## 
## Started on  Thu Apr  7 14:38:16 2016 Berthaud Elodie
## Last update Sun May 22 22:09:34 2016 Berthaud Elodie
##

NAME	=	solver

SRC	=	src/generation_arbre/file.c \
		src/generation_arbre/tab_cell.c \
		src/generation_arbre/ressources.c \
		src/generation_arbre/link_cells.c \
		src/generation_arbre/link_cell_conditions.c \
		src/generation_arbre/link_cell_suite.c \
		src/pathfinding/main.c \
		src/pathfinding/call_function.c \
		src/pathfinding/path.c \
		src/pathfinding/my_circ_list.c \
		src/pathfinding/print_end_maze.c \
		src/pathfinding/check_available_maze.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-g -W -Wall -Iinclude/

$(NAME):$(OBJ)		
	$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
