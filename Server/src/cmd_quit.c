/*
** cmd_quit.c for cmd_quit in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Mon Jun  5 21:46:49 2017 Leo Le Diouron
** Last update Mon Jun  5 22:15:24 2017 Leo Le Diouron
*/

#include "server.h"

bool	quit(t_server *server, char **params, int fd_client)
{
  int	i;

  (void)params;
  i = 0;
  while (i < SIZE_USERNAME)
    server->users[fd_client].nickname[i++] = 0;
  i = 0;
  while (i < MAX_FD)
    server->chans[i++].users[fd_client] = 0;
  server->e.fd_type[fd_client] = FD_FREE;
  close(fd_client);
  return (true);
}
