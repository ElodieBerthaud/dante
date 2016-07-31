/*
** link_cell_conditions.c for  in /home/bertha_e/rendu/CLONES/dante/src/generation_arbre
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Sun May 22 19:06:57 2016 Berthaud Elodie
** Last update Sun May 22 22:54:37 2016 Berthaud Elodie
*/

#include <stdlib.h>
#include "maze.h"

void		check_on_right(char **tab, t_data *data,
			       t_tree *cell, t_tree **tree)
{
  t_manage	manage;

  if (tab[data->i][data->j + 1] != '\0' && tab[data->i][data->j + 1] == '*')
    {
      manage.i = data->i;
      manage.j = data->j + 1;
      loop(cell, &manage, tree);
    }
}

void		check_on_left(char **tab, t_data *data,
			      t_tree *cell, t_tree **tree)
{
  t_manage	manage;

  if (data->j != 0 && tab[data->i][data->j - 1] == '*')
    {
      manage.i = data->i;
      manage.j = data->j - 1;
      loop(cell, &manage, tree);
    }
}

void		check_at_bottom(char **tab, t_data *data,
				t_tree *cell, t_tree **tree)
{
  t_manage	manage;

  if (data->i != 0 && tab[data->i - 1][data->j] == '*')
    {
      manage.i = data->i - 1;
      manage.j = data->j;
      loop(cell, &manage, tree);
    }
}

void		check_at_top(char **tab, t_data *data,
			     t_tree *cell, t_tree **tree)
{
  t_manage	manage;

  if (tab[data->i + 1] != NULL && tab[data->i + 1][data->j] == '*')
    {
      manage.i = data->i + 1;
      manage.j = data->j;
      loop(cell, &manage, tree);
    }
}
