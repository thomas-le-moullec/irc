/*
** initialisation.c for initialisation in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc/Server/src
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun May 28 14:33:40 2017 Thomas LE MOULLEC
** Last update Sun Jun 11 14:16:52 2017 Leo Le Diouron
*/

#include "server.h"

void		initialise_server(t_server *server, char *port)
{
  int		i;

  i = 0;
  server->fd = 0;
  server->e.port = atoi(port);
  server->ip = LOCALHOST;
  server->tv.tv_sec = 20;
  server->tv.tv_usec = 0;
  FD_ZERO(&server->fd_read);
  FD_ZERO(&server->fd_write);
  memset(server->e.fd_type, 0, MAX_FD);
  memset(server->chans, 0, MAX_FD * sizeof(t_chan));
  memset(server->users, 0, MAX_FD * sizeof(t_user));
  while (i < MAX_FD)
    {
      server->users[i].msg.is_empty = true;
      server->users[i++].last_chan = -1;
    }
  add_server(server);
}

void		set_fds(t_server *server)
{
  int		i;

  i = 0;
  while (i < MAX_FD)
    {
      if (server->e.fd_type[i] != FD_FREE)
	{
	  FD_SET(i, &server->fd_read);
	  if (server->users[i].msg.is_empty == false)
	    FD_SET(i, &server->fd_write);
	  server->fd_max = i;
	}
      i++;
    }
}
