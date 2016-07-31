##
## Makefile for perfect lab in /home/darrig_s/PROJETS/IA/dante/sophie
## 
## Made by Sophie Darrigol
## Login   <darrig_s@epitech.net>
## 
## Started on  Fri Apr 29 05:49:46 2016 Sophie Darrigol
## Last update Sat May 21 22:00:34 2016 Sophie Darrigol
##

NAME	=	generateur

SRC	=	sources/perfect_lab.c \
		sources/pile_functions.c \
		sources/flanders.c \
		sources/my_getnbr.c	

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-g -W -Wall -Wextra -Iinclude/	

$(NAME):$(OBJ)		
	$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
