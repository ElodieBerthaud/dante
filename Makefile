##
## Makefile for  in /home/bertha_e/rendu/CLONES/dante
## 
## Made by Berthaud Elodie
## Login   <bertha_e@epitech.net>
## 
## Started on  Sun May 22 23:03:12 2016 Berthaud Elodie
## Last update Fri May 27 17:10:28 2016 Berthaud Elodie
##

all:
	make -C ./generateur
	make -C ./profondeur
	make -C ./astar
	make -C ./largeur
	make -C ./tournoi

clean:
	make clean -C ./generateur
	make clean -C ./profondeur
	make clean -C ./largeur
	make clean -C ./astar
	make clean -C ./tournoi

fclean:
	make fclean -C ./generateur
	make fclean -C ./profondeur
	make fclean -C ./largeur
	make fclean -C ./astar
	make fclean -C ./tournoi

re: fclean all
