/*
** call_function.c for  in /home/bertha_e/rendu/Initiation_IA/dante/src/pathfinding
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Mon May  9 15:38:24 2016 Berthaud Elodie
** Last update Sun May 22 22:58:13 2016 Berthaud Elodie
*/

#include <stdlib.h>
#include "maze.h"

int            call_functions(char *file)
{
  char          **tab;
  int           l;
  int           L;
  t_tree        **tree;
  t_pos		end;

  if ((tab = stock_maze(file)) == NULL)
    return (-1);
  l = get_high_size(tab);
  L = my_strlen(tab[0]);
  end.i = l - 1;
  end.j = L - 2;
  if ((tree = tree_tab(tab, l, L, 0)) == NULL)
    return (-1);
  build_tree(tab, tree, 0, 0);
  if (( path(*tree, 0, tab, &end)) == -1)
    return (-1);
  return (0);
}
