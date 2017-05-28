/*
** channel.c for channel in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun May 28 13:46:02 2017 Leo Le Diouron
** Last update Sun May 28 13:48:09 2017 Leo Le Diouron
*/

#include "server.h"

t_chan  *add_channel(t_chan *chans, char *name, t_user *users)
{
  t_chan        *new;

  if ((new = malloc(sizeof(t_chan))) == NULL)
    exit(0);
  new->name = strdup(name);
  new->users = users;
  if (chans == NULL)
    {
      new->prev = NULL;
      new->next = NULL;
      chans = new;
    }
  else
    {
      while (chans->next != NULL)
	chans = chans->next;
      new->next = NULL;
      new->prev = chans;
      chans->next = new;
      while (chans->prev != NULL)
	chans = chans->prev;
    }
  return (chans);
}
