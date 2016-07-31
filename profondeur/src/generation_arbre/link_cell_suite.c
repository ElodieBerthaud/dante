/*
** link_cell_suite.c for  in /home/bertha_e/rendu/CLONES/dante/src/generation_arbre
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Sun May 22 19:01:01 2016 Berthaud Elodie
** Last update Sun May 22 22:28:30 2016 Berthaud Elodie
*/

#include <stdlib.h>
#include "maze.h"

int             get_next_nbr(char **tab, int i, int j)
{
  int           next;

  next = 0;
  if (tab[i][j + 1] != '\0' && tab[i][j + 1] == '*')
    next++;
  if (j != 0 && tab[i][j - 1] == '*')
    next++;
  if (i != 0 && tab[i - 1][j] == '*')
    next++;
  if (tab[i + 1] != NULL && tab[i + 1][j] == '*')
    next++;
  return (next + 1);
}

void            init_to_null(t_tree *cell, int size)
{
  int           i;

  i = 0;
  while (i < size)
    {
      cell->next[i] = NULL;
      i++;
    }
}
