/*
** pile_functions.c for dante in /home/darrig_s/PROJETS/IA/dante/sophie/sources
** 
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
** 
** Started on  Fri Apr 29 05:57:58 2016 Sophie Darrigol
** Last update Sat May 21 21:51:32 2016 Sophie Darrigol
*/

#include "dante.h"
#include <stdlib.h>

void		pile_push(t_pile **p_pile, int i, int j)
{
  t_pile	*p_new;

  if ((p_new = malloc(sizeof(t_pile))) != NULL)
    {
      p_new->i = i;
      p_new->j = j;
      if (*p_pile != NULL)
	p_new->prev = (*p_pile);
      (*p_pile) = p_new;
    }
}

int		pile_pop(t_pile **p_pile)
{
  t_pile	*tmp;
  int		ret = -1;

  if ((tmp = malloc(sizeof(tmp))) == NULL)
    return (-1);
  if (p_pile != NULL)
    {
      tmp = (*p_pile)->prev;
      ret = (*p_pile)->i;
      ret = (*p_pile)->j;
      free(*p_pile);
      *p_pile = NULL;
      *p_pile = tmp;
    }
  return (ret);
}

void	pile_clear(t_pile **p_pile)
{
  while (*p_pile != NULL)
    {
      pile_pop(p_pile);
    }
}
