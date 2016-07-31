/*
** tab_cell.c for path in /home/bertha_e/rendu/Initiation_IA/dante/src
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Mon May  2 11:39:04 2016 Berthaud Elodie
** Last update Sun May 22 22:57:28 2016 Berthaud Elodie
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "maze.h"

int		get_high_size(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

t_tree		**tree_tab(char **tab, int l, int L, int x)
{
  t_tree	**tree;
  int		i;
  int		j;

  if ((tree = malloc_tree(tab, l, L)) == NULL)
    return (NULL);
  i = -1;
  j = -1;
  while (++i < l)
    {
      while (++j < L)
  	{
  	  if (tab[i][j] == '*')
  	    {
  	      tree[x]->i = i;
  	      tree[x]->j = j;
  	      tree[x]->bol = 0;
	      x++;
	    }
	}
      j = -1;
    }
  tree[x] = NULL;
  return (tree);
}

int		first_browse(char **tab, int l, int L)
{
  int		i;
  int		j;
  int		stk;

  i = 0;
  j = 0;
  stk = 0;
  while (i < l)
    {
      while (j < L)
	{
	  if (tab[i][j] == '*')
	    stk++;
	  j++;
	}
      j = 0;
      i++;
    }
  return (stk);
}

t_tree		**malloc_tree(char **tab, int l, int L)
{
  int		stk;
  int		i;
  t_tree	**tree;

  stk = first_browse(tab, l, L);
  i = 0;
  if ((stk == 0))
    {
      printf("Maze not valid\n");
      return (NULL);
    }
  if ((tree = malloc(sizeof(t_tree *) * (stk + 1))) == NULL)
    return (NULL);
  while (i <= stk)
    {
      if ((tree[i] = malloc(sizeof(t_tree))) == NULL)
	return (NULL);
      i++;
    }
  return (tree);
}
