/*
** ressources.c for  in /home/bertha_e/rendu/Initiation_IA/dante/src
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Wed May  4 16:44:53 2016 Berthaud Elodie
** Last update Sun May 22 20:09:58 2016 Berthaud Elodie
*/

#include <unistd.h>
#include <stdlib.h>
#include "maze.h"

void	my_putchar(const char c)
{
  write(1, &c, 1);
}

void	my_putstr(const char *str)
{
  int	i;

  i = 0;
  while (str[i++] != '\0')
    my_putchar(str[i]);
}

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char    *my_strdup(char *str)
{
  int   i;
  int   j;
  char  *stk;

  i = my_strlen(str) + 1;
  j = 0;
  if ((stk = malloc(i * sizeof(char))) == NULL)
    return (NULL);
  while (str != NULL && str[j] != '\0')
    {
      stk[j] = str[j];
      j++;
    }
  stk[j] = '\0';
  return (stk);
}
