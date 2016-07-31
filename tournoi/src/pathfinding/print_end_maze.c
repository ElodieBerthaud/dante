/*
** print_end_maze.c for  in /home/bertha_e/rendu/CLONES/dante/src/pathfinding
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Sat May 21 23:36:21 2016 Berthaud Elodie
** Last update Sun May 22 20:11:03 2016 Berthaud Elodie
*/

#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

void	print_final(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      printf("%s", tab[i]);
      i++;
    }
}

void	print_end(char **tab, t_pile *pile)
{
  while (pile != NULL)
    {
      tab[pile->cell->i][pile->cell->j] = 'o';
      pile = pile->next;
    }
  print_final(tab);
}
