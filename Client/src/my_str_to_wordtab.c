/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat May 27 17:55:45 2017 Thomas LE MOULLEC
** Last update Sat May 27 17:58:03 2017 Thomas LE MOULLEC
*/

#include "client.h"

char            **my_str_to_wordtab(char *str, char c)
{
  int           i;
  int           x;
  int           y;
  char          **tab;

  y = 0;
  i = 0;
  tab = NULL;
  tab = malloc(sizeof(char *) * (strlen(str) + 1));
  while (str[i] != '\0')
    {
      x = 0;
      while (str[i] == c)
	i++;
      tab[y] = NULL;
      tab[y] = malloc(sizeof(char) * (strlen(str) + 1));
      while (str[i] != '\0' && str[i] != c)
	tab[y][x++] = str[i++];
      tab[y][x] = '\0';
      y++;
      if (str[i] != '\0')
	i++;
    }
  tab[y] = NULL;
  return (tab);
}
