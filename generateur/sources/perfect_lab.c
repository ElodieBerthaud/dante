/*
** perfect_lab.c for génération labyrinthe parfait in /home/darrig_s/PROJETS/IA/dante/sophie
** 
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
** 
** Started on  Fri Apr 29 05:09:30 2016 Sophie Darrigol
** Last update Sat May 21 21:57:41 2016 Sophie Darrigol
*/

#include "dante.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

void	display(char **tab, int larg, int haut)
{
  int	i;
  int	j;

  i = -1;
  while (++i < haut)
    {
      j = -1;
      while (++j < larg)
	write(1, &tab[i][j], 1);
      if (i + 1 < haut)
	write(1, "\n", 1);
    }
}

int		algo(char **tab, t_pile *p_pile, t_coord *coord)
{
  tab[0][0] = '*';
  pile_push(&p_pile, 0, 0);
  while (p_pile != NULL)
    {
      if (flanders(tab, coord) != -1)
	{
	  tab[coord->cell.i][coord->cell.j] = '*';
	  pile_push(&p_pile, coord->cell.i, coord->cell.j);
	}
      else
	{
	  coord->cell.i = p_pile->i;
	  coord->cell.j = p_pile->j;
	  if (p_pile->i == 0 && p_pile->j == 0)
	    p_pile = NULL;
	  else
	    pile_pop(&p_pile);
 	}
    }
  pile_clear(&p_pile);
  if (coord->haut > 1 && coord->larg > 1)
    end(tab, coord->haut, coord->larg);
  else
    tab[coord->haut - 1][coord->larg - 1] = '*';
  return (0);
}

char	**full_tab(char **tab, t_coord *coord)
{
  int	i;
  int	j;

  i = -1;
  while (++i < coord->haut)
    {
      j = -1;
      while (++j < coord->larg)
	tab[i][j] = 'X';
    }
  return (tab);
}

int		create_tab(t_coord *coord, int a)
{
  char		**tab;
  int		i;
  t_pile	*p_pile;

  i = -1;
  if ((p_pile = malloc(sizeof(p_pile))) == NULL)
    return (-1);
  if ((tab = malloc(coord->haut * sizeof(char *) + 1)) == NULL)
    return (-1);
  while (++i < coord->haut)
    if ((tab[i] = malloc(coord->larg * sizeof(char) + 1)) == NULL)
      return (-1);
  tab = full_tab(tab, coord);
  if (algo(tab, p_pile, coord) != 0)
    return (-1);
  i = -1;
  if (a == 1)
    while (++i < (coord->haut * coord->larg) / 10)
      tab[rand() % (coord->haut - 1)][rand() % (coord->larg - 1)] = '*';
  display(tab, coord->larg, coord->haut);
  i = -1;
  while (++i < coord->haut)
    free(tab[i]);
  free(tab);
  return (0);
}

int		main(int ac, char **av)
{
  t_coord	*coord;

  srand(time(NULL));
  if ((coord = malloc(sizeof(t_coord))) == NULL)
    return (-1);
  coord->cell.i = 0;
  coord->cell.j = 0;
  if (ac < 3)
    return (-1);
  if ((coord->haut = my_getnbr(av[1])) <= 0 ||
      (coord->larg = my_getnbr(av[2])) <= 0)
    return (-1);
  if (ac == 4 && strcmp(av[3], "parfait") == 0)
    {
      if (create_tab(coord, 0) != 0)
	return (-1);
    }
  else if (ac == 3)
    if (create_tab(coord, 1) != 0)
      return (-1);
  free(coord);
  return (0);
}
