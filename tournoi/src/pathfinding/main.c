/*
** main.c for  in /home/bertha_e/rendu/Initiation_IA/dante/src/pathfinding
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Mon May  9 14:34:47 2016 Berthaud Elodie
** Last update Sun May 22 22:58:25 2016 Berthaud Elodie
*/

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int             main(int ac, char **av)
{
  if (ac == 2)
    {
      if ((call_functions(av[1])) == -1)
	return (-1);
    }
  else
    printf("Usage: ./solver [file name]\n");
  return (0);
}

