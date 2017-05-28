/*
** initialisation.c for initialisation in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc/Server/src
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun May 28 14:33:40 2017 Thomas LE MOULLEC
** Last update Sun May 28 15:11:30 2017 Thomas LE MOULLEC
*/

#include "server.h"

void		initialise_server(t_server *server, char *port)
{
  server->chan = NULL;
  server->users = NULL;
  server->fd = 0;
  server->e.port = atoi(port);
  server->ip = LOCALHOST;
  server->tv.tv_sec = 20;
  server->tv.tv_usec = 0;
  FD_ZERO(&server->fd_read);
  memset(server->e.fd_type, 0, MAX_FD);
  add_server(&server->e);
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
	  server->fd_max = i;
	}
      i++;
    }
}
