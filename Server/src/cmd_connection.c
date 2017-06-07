/*
** cmd_connection.c for cmd_connection in /home/le-dio_l/PSU_2016_myirc/Server/src
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Jun  3 10:23:04 2017 Leo Le Diouron
** Last update Wed Jun  7 21:20:48 2017 Leo Le Diouron
*/

#include "server.h"

bool	connection(t_server *server, char **params, int fd_client)
{
  int	i;

  i = 0;
  if (params[1] == NULL || strlen(params[1]) > 64)
    return (false);
  while (params[1][i] != '\0')
    {
      server->users[fd_client].nickname[i] = params[1][i];
      i++;
    }
  if (server->users[fd_client].is_activated == true)
    dprintf(fd_client, WELCOME);
  else
    server->users[fd_client].is_activated = true;
  return (true);
}

bool    check_user(t_server *server, char **params, int fd_client)
{
  (void)params;
  if (server->users[fd_client].is_activated == true)
    dprintf(fd_client, WELCOME);
  else
    server->users[fd_client].is_activated = true;
  return (true);
}
