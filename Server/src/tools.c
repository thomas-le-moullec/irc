/*
** tools.c for tools in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Jun  3 10:47:46 2017 Thomas LE MOULLEC
** Last update Sat Jun  3 11:28:52 2017 Thomas LE MOULLEC
*/

#include "server.h"

void		*free_tab(char **tab)
{
  unsigned int 	y;

  y = 0;
  if (tab != NULL)
    {
      while (tab[y] != NULL)
	{
	  free(tab[y]);
	  y++;
	}
      free(tab);
    }
  return (NULL);
}

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
