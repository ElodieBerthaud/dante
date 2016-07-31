/*
** path.c for path in /home/bertha_e/rendu/Initiation_IA/dante/src/pathfinding
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Mon May  9 15:38:32 2016 Berthaud Elodie
** Last update Sun May 22 22:59:01 2016 Berthaud Elodie
*/

#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

int		depile(t_pile **pile)
{
  if (((*pile)->cell->i == 0 && (*pile)->cell->j == 0))
    {
      if ((check_maze((*pile)->cell) == 1))
	printf("No solution found\n");
      return (-1);
    }
  *pile = (*pile)->next;
  free((*pile)->prev);
  return (0);
}

int		check_bol(t_tree *cell)
{
  int		x;

  x = 0;
  while (cell->next[x] != NULL)
    {
      if (cell->next[x]->bol == 0)
	return (x);
      x++;
    }
  x = 0;
  while (cell->next[x] != NULL)
    {
      if (cell->next[x]->bol == 2)
	return (x);
      x++;
    }
  return (0);
}

int		path_empile(t_tree **cell, t_pile **pile, int x)
{
  add_in_list(pile, *cell);
  (*cell)->bol = 2;
  *cell = (*cell)->next[x];
  x = 0;
  return (x);
}

int		path_depile(t_tree **cell, t_pile **pile, int x)
{
  if ((*cell)->next[x] != NULL)
    x++;
  if ((*cell)->next[x] == NULL)
    {
      x = check_bol(*cell);
      if ((*cell)->next[x]->bol == 2)
	{
	  (*cell)->bol = 1;
	  if ((depile(pile)) == -1)
	    return (-1);
	  *cell = (*pile)->cell;
	  x = 0;
	}
    }
  return (x);
}

int		path(t_tree *cell, int x, char **tab, t_pos *end)
{
  t_pile	*pile;

  if ((pile = malloc(sizeof(t_pile))) == NULL)
    return (-1);
  pile = NULL;
  while ((cell->i != end->i) || (cell->j != end->j))
    {
      if (cell->next[x] == NULL)
	x = 0;
      if (cell && cell->next[x] != NULL && cell->next[x]->bol == 0)
	x = path_empile(&cell, &pile, x);
      else
	if ((x = path_depile(&cell, &pile, x)) == -1)
	  return (-1);
    }
  add_in_list(&pile, cell);
  print_end(tab, pile);
  return (0);
}
