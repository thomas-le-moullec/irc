/*
** user.c for user in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat May 27 17:16:26 2017 Leo Le Diouron
** Last update Sat May 27 18:02:53 2017 Leo Le Diouron
*/

#include "server.h"

t_user	*add_user(t_user *users, char *nickname, int fd, t_chan *chan)
{
  t_user	*new;

  if ((new = malloc(sizeof(t_user))) == NULL)
    exit(0);
  new->nickname = strdup(nickname);
  new->fd = fd;
  new->chans = chan;
  if (users == NULL)
    {
      new->prev = NULL;
      new->next = NULL;
      users = new;
    }
  else
    {
      while (users->next != NULL)
	users = users->next;
      new->next = NULL;
      new->prev = users;
      users->next = new;
      while (users->prev != NULL)
	users = users->prev;
    }
  return (users);
}
