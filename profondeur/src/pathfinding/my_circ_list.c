/*
** main.c for  in /home/bertha_e/rendu/CPE_2015_Pushswap
** 
** Made by elodie berthaud
** Login   <bertha_e@epitech.net>
** 
** Started on  Wed Nov 18 16:20:45 2015 elodie berthaud
** Last update Sun May 22 21:54:20 2016 Berthaud Elodie
*/

#include <stdlib.h>
#include "maze.h"

int		add_in_list(t_pile **l_a, t_tree *cell)
{
  t_pile	*temp;

  temp = malloc(sizeof(t_pile));
  if (temp == NULL)
    return (0);
  if (*l_a != NULL)
    (*l_a)->prev = temp;
  temp->cell = cell;
  temp->bol = 2;
  temp->next = (*l_a);
  *l_a = temp;
  return (1);
}
