/*
** tools.c for tools in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Jun  3 10:47:46 2017 Thomas LE MOULLEC
** Last update Sat Jun  3 10:51:33 2017 Thomas LE MOULLEC
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
