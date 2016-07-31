/*
** my_getnbr.c for my_getnbr in /home/darrig_s/PISCINE_C/Piscine_C_evalexpr
** 
** Made by Sophie Darrigol
** Login   <darrig_s@epitech.net>
** 
** Started on  Tue Nov 17 11:44:28 2015 Sophie Darrigol
** Last update Sat May 21 21:54:24 2016 Sophie Darrigol
*/

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	signe;

  i = 0;
  nb = 0;
  signe = 1;
  while (str[i] != '\0' && (str[i] == 43 || str[i] == 45))
    {
      if (str[i] == 45)
	signe = -(signe);
      i = i + 1;
    }
  while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
    {
      nb = (nb * 10) + (str[i] - 48);
      i = i + 1;
    }
  if (str[i] != '\0')
    return (-2);
  if (nb >= 2147483647)
    return (0);
  return (nb * signe);
}
