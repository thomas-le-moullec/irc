/*
** tools.c for tools in /home/le-dio_l/PSU_2016_myirc/ClientTest
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun Jun  4 10:47:37 2017 Leo Le Diouron
** Last update Sun Jun  4 10:47:50 2017 Leo Le Diouron
*/

#include "client.h"

char            **initialise_tab(char *str)
{
  char          **tab;

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
