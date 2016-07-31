/*
** main.c for  in /home/bertha_e/rendu/Initiation_IA/dante/src/pathfinding
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Mon May  9 14:34:47 2016 Berthaud Elodie
** Last update Sat May 21 23:25:31 2016 Sophie Darrigol
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"

int             main(int ac, char **av)
{
  if (ac == 2 && strcmp(&av[1][strlen(av[1]) - 4], ".txt") == 0)
    {
      if ((call_functions(av[1])) == -1)
	return (-1);
    }
  else
    printf("Usage: ./solver [filename.txt]\n");
  return (0);
}

