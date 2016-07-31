/*
** file.c for file in /home/bertha_e/rendu/Initiation_IA/dante/src
** 
** Made by Berthaud Elodie
** Login   <bertha_e@epitech.net>
** 
** Started on  Fri Apr 29 14:43:24 2016 Berthaud Elodie
** Last update Sun May 22 22:52:15 2016 Berthaud Elodie
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "maze.h"

char    **add_in_tab(char **tab, char *line)
{
  char  **stk;
  int   i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  if ((stk = malloc(sizeof(char *) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    {
      if ((stk[i] = my_strdup(tab[i])) == NULL)
	return (NULL);
      i++;
    }
  if ((stk[i] = my_strdup(line)) == NULL)
    return (NULL);
  stk[i + 1] = NULL;
  return (stk);
}

char		**strcp(char **tab, char *line, int l, int L)
{
  int		i;
  int		j;
  static int	pos = 0;

  i = 0;
  j = 0;
  while (i < l)
    i++;
  while (j < L)
    {
      if (line[j] == '\n')
	tab[i][j] = '\0';
      tab[i][j] = line[j];
      j++;
    }
  if (pos == l)
    tab[i + 1] = NULL;
  pos++;
  return (tab);
}

int		check_file(char *file)
{
  struct stat	sb;

  stat(file, &sb);
  if (sb.st_size == 0)
    {
      printf("Attention: the file is empty\n");
      return (-1);
    }
  return (0);
}

char		**stock_maze(char *file)
{
  char		*str;
  char		**tab;
  FILE		*stream;
  ssize_t	read;
  size_t	len;

  if ((check_file(file)) == -1)
    return (NULL);
  if ((stream = fopen(file, "r")) == NULL)
    return (NULL);
  if ((tab = malloc(sizeof(char *))) == NULL)
    return (NULL);
  tab[0] = NULL;
  len = 0;
  str = NULL;
  while ((read = getline(&str, &len, stream)) != -1)
    tab = add_in_tab(tab, str);
  if ((tab == NULL))
    {
      printf("The file is Empty\n");
      return (NULL);
    }
  return (tab);
}
