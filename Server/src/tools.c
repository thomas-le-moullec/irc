/*
** tools.c for tools in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Jun  3 10:47:46 2017 Thomas LE MOULLEC
** Last update Sun Jun 11 15:09:04 2017 Leo Le Diouron
*/

#include "server.h"

void		*free_tab(char **tab)
{
  unsigned int 	y;

  y = 0;
  if (tab != NULL)
    {
      while (tab[y] != NULL)
	free(tab[y++]);
      free(tab);
    }
  return (NULL);
}

char		**initialise_tab(char *str)
{
  char		**tab;

  tab = NULL;
  if ((tab = malloc(sizeof(char *) * (strlen(str) + 1))) == NULL)
    exit(ERROR);
  return (tab);
}

char            **my_str_to_wordtab(char *str, char c)
{
  int           i;
  int           x;
  int           y;
  char          **tab;

  y = -1;
  i = 0;
  tab = initialise_tab(str);
  while (str[i] != '\0')
    {
      x = 0;
      while (str[i] == c)
	i++;
      tab[++y] = NULL;
      if ((tab[y] = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
	exit(ERROR);
      while (str[i] != '\0' && str[i] != c)
	tab[y][x++] = str[i++];
      tab[y][x] = '\0';
      if (str[i] != '\0')
	i++;
    }
  tab[++y] = NULL;
  return (tab);
}

char		*upper_str(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      str[i] = toupper(str[i]);
      i++;
    }
  return (str);
}
