/*
** orders.c for orders in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc/Server/src
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Jun  3 10:31:07 2017 Thomas LE MOULLEC
** Last update Sat Jun  3 17:42:58 2017 Thomas LE MOULLEC
*/

#include "server.h"

int             loop_on_char(char *str, int i, char c)
{
  while (str[i] == c)
    i++;
  return (i);
}

char		*fill_order(char *str, int *i, char c)
{
  char		*order;
  int		x;

  order = NULL;
  if ((order = malloc(sizeof(char) * (strlen(str) - *i + 1))) == NULL)
    exit(ERROR);
  x = 0;
  while (str[*i] != '\0' && str[*i] != c)
    order[x++] = str[(*i)++];
  order[x] = 0;
  if (str[*i] != c)
    {
      free(order);
      order = NULL;
    }
  //  printf("ORDER => %s\n", order);
  return (order);
}

char            **get_orders(char *str)
{
  char          **tab;
  int		i;
  int		y;

  i = 0;
  y = 0;
  tab = NULL;
  if ((tab = malloc(sizeof(char *) * (strlen(str) + 1))) == NULL)
      exit(ERROR);
  while (str[i] != '\0')
    {
      tab[y] = NULL;
      i = loop_on_char(str, i, SEP1);
      tab[y] = fill_order(str, &i, SEP1);
      if (str[i] != '\0')
	i++;
      y++;
    }
  tab[y] = NULL;
  return (tab);
}
