/*
** link_cells.c for  in /home/bertha_e/rendu/Initiation_IA/dante/src
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Tue May  3 13:36:36 2016 Berthaud Elodie
** Last update Sun May 22 22:54:57 2016 Berthaud Elodie
*/

#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

int		malloc_cell_next(t_tree *cell, int size)
{
  int		x;

  x = 0;
  if ((cell->next = malloc(sizeof(t_tree *) * size)) == NULL)
    return (-1);
  while (x < size)
    {
      if ((cell->next[x] = malloc(sizeof(t_tree))) == NULL)
	return (-1);
      x++;
    }
  init_to_null(cell, size);
  return (0);
}

void		loop(t_tree *cell, t_manage *manage, t_tree **tree)
{
  int		i;
  int		a;

  i = 0;
  a = 0;
  while (cell->next[a] != NULL)
    a++;
  while (tree[i] != NULL)
    {
      if (tree[i]->i == manage->i && tree[i]->j == manage->j)
	cell->next[a] = tree[i];
      i++;
    }
}

void		link_cells(char **tab, t_data *data, t_tree *cell, t_tree **tree)
{
  check_on_right(tab, data, cell, tree);
  check_on_left(tab, data, cell, tree);
  check_at_bottom(tab, data, cell, tree);
  check_at_top(tab, data, cell, tree);
}

t_tree		*get_current_cell(t_tree **tree, int i, int j)
{
  int		x;

  x = 0;
  while (tree[x]-> i != i || tree[x]->j != j)
    x++;
  return (tree[x]);
}

void		*build_tree(char **tab, t_tree **tree, int i, int j)
{
  t_data	data;
  t_tree	*cell;

  cell = (*tree);
  while (tab[i] != NULL)
    {
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] == '*')
	    {
	      data.i = i;
	      data.j = j;
	      cell = get_current_cell(tree, i, j);
	      if ((malloc_cell_next(cell, get_next_nbr(tab, i, j))) == -1)
		return (NULL);
	      link_cells(tab, &data, cell, tree);
	    }
	  j++;
	}
      j = 0;
      i++;
    }
  return (*tree);
}
