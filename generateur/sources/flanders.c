/*
** flanders.c for perfect lab suite in /home/darrig_s/PROJETS/IA/dante/sophie/sources
** 
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
** 
** Started on  Tue May  3 03:28:29 2016 Sophie Darrigol
** Last update Sat May 21 21:53:59 2016 Sophie Darrigol
*/

#include "dante.h"
#include <stdlib.h>

void	end(char **tab, int haut, int larg)
{
  int	a;

  a = 1 + rand() % 2;
  if (a == 1 && tab[haut - 2][larg - 1] != '*')
    tab[haut - 1][larg - 2] = '*';
  else
    tab[haut - 2][larg - 1] = '*';
  tab[haut - 1][larg - 1] = '*';
}

int	next(int **voisin, t_coord *coord, char **tab, int a)
{
  int	b;

  b = -1;
  if (coord->i < 0 || coord->j < 0)
    b = 1;
  if (coord->j == 0 && coord->cell.i + coord->i > 0 &&
      coord->cell.i + coord->i < coord->haut &&
      tab[coord->cell.i + coord->i][coord->cell.j] == 'X')
    {
      a++;
      voisin[a][0] = coord->cell.i + coord->i + b;
      voisin[a][1] = coord->cell.j;
      voisin[a][2] = coord->cell.i + coord->i;
      voisin[a][3] = coord->cell.j;
    }
  if (coord->i == 0 && coord->cell.j + coord->j < coord->larg &&
      coord->cell.j + coord->j > 0 && tab[coord->cell.i][coord->cell.j + coord->j] == 'X')
    {
      a++;
      voisin[a][0] = coord->cell.i;
      voisin[a][1] = coord->cell.j + coord->j + b;
      voisin[a][2] = coord->cell.i;
      voisin[a][3] = coord->cell.j + coord->j;
    }
  return (a);
}

int	choice(int a, char **tab, t_coord *coord, int **voisin)
{
  if (a != -1)
    {
      if (a != 0)
	a = rand() % (a + 1);
      tab[voisin[a][0]][voisin[a][1]] = '*';
      coord->cell.i = voisin[a][2];
      coord->cell.j = voisin[a][3];
      return (0);
    }
  return (-1);
}

int	full_choice(int **voisin, char **tab, t_coord *coord)
{
  int	a;
  int	b;

  a = -1;
  b = -1;
  coord->i = -2;
  while (++b < 5)
    {
      coord->j = 0;
      a = next(voisin, coord, tab, a);
      coord->j = -2;
      coord->i = 0;
      while (++b < 3)
	{
	  a = next(voisin, coord, tab, a);
	  coord->j = coord->j + 4;
	}
      coord->i = coord->i + 2;
    }
  if (choice(a, tab, coord, voisin) != -1)
    return (0);
  return (-1);
}

int	flanders(char **tab, t_coord *coord)
{
  int	**voisin;
  int	a;
  int	end;

  a = -1;
  coord->i = 0;
  coord->j = 0;
  if ((voisin = malloc(sizeof(int *) * 4)) == NULL)
    return (-1);
  while (++a < 4)
    if ((voisin[a] = malloc(sizeof(int) * 4)) == NULL)
      return (-1);
  end = full_choice(voisin, tab, coord);
  a = -1;
  while (++a < 4)
    free(voisin[a]);
  free(voisin);
  if (end == 0)
    return (0);
  return (-1);
}
