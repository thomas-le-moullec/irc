/*
** initialisation_client.c for initialisation_client in /home/le-dio_l/PSU_2016_myirc/ClientTest
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun Jun  4 09:54:35 2017 Leo Le Diouron
** Last update Mon Jun 12 13:56:06 2017 Leo Le Diouron
*/

#include "client.h"

void            initialise_client(t_client *client)
{
  client->fd = 0;
  client->tv.tv_sec = 20;
  client->tv.tv_usec = 0;
  FD_ZERO(&client->fd_read);
  FD_ZERO(&client->fd_write);
  memset(client->e.fd_type, 0, MAX_FD);
  add_client(client);
}

void            set_fds(t_client *client)
{
  int           i;

  i = 0;
  while (i < MAX_FD)
    {
      if (client->e.fd_type[i] != FD_FREE)
	{
	  FD_SET(i, &client->fd_read);
	  client->fd_max = i;
	}
      i++;
    }
}
