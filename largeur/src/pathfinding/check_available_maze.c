/*
** check_available_maze.c for  in /home/bertha_e/rendu/CLONES/dante/src/pathfinding
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Sun May 22 20:12:45 2016 Berthaud Elodie
** Last update Sun May 22 22:04:27 2016 Berthaud Elodie
*/

#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

int		check_all_next(t_tree *cell)
{
  int		x;

  x = 0;
  while (cell->next[x] != NULL)
    {
      if (cell->next[x]->bol == 2 || cell->next[x]->bol == 0)
	return (0);
      x++;
    }
  return (-1);
}

int		check_maze(t_tree *cell)
{
  int		x;

  x = 0;
  while (cell->next[x] != NULL)
    {
      if (cell->next[x] == 0)
	return (1);
    }
  return (0);
}
