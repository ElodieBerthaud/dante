/*
** dante.h for dante in /home/darrig_s/PROJETS/IA/dante/sophie/include
** 
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
** 
** Started on  Fri Apr 29 05:39:15 2016 Sophie Darrigol
** Last update Sat May 21 21:59:02 2016 Sophie Darrigol
*/

#ifndef DANTE_H_
# define DANTE_H_

typedef struct	s_pile
{
  int		i;
  int		j;
  struct s_pile *prev;
}		t_pile;

typedef struct	s_courante
{
  int		i;
  int		j;
}		t_courante;

typedef struct	s_coord
{
  int		i;
  int		j;
  int		larg;
  int		haut;
  t_courante	cell;
  
}		t_coord;

int	my_getnbr(char *str);
void	pile_push(t_pile **p_pile, int i, int j);
int	pile_pop(t_pile **p_pile);
void	pile_clear(t_pile **p_pile);
int	flanders(char **tab, t_coord *coord);
void	end(char **tab, int haut, int larg);

#endif /*DANTE_H_ */
