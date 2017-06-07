/*
** fill_queue.c for fill_queue in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Mon Jun  5 21:02:04 2017 Leo Le Diouron
** Last update Mon Jun  5 21:13:52 2017 Leo Le Diouron
*/

#include "server.h"

void	fill_queue(t_server *server, int idx, char *msg)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < SIZE_MSG && server->users[idx].msg.queue[j][0] != '\0')
    j++;
  if (j != SIZE_MSG)
    {
      while (msg[i] != '\0')
	{
	  server->users[idx].msg.queue[j][i] = msg[i];
	  i++;
	}
      server->users[idx].msg.queue[j][i] = '\0';
      server->users[idx].msg.is_empty = false;
    }
}
