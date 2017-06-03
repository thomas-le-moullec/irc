/*
** cmd_connection.c for cmd_connection in /home/le-dio_l/PSU_2016_myirc/Server/src
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Jun  3 10:23:04 2017 Leo Le Diouron
** Last update Sat Jun  3 10:32:37 2017 Leo Le Diouron
*/

#include "server.h"

bool	connection(t_server *server, char **params, int fd_client)
{
  if (params[1] == NULL || strlen(params[1]) > 64)
    return (false);
  server->users[fd_client].nickname = params[1];
  return (true);
}

bool	authentification_channel(t_server *server, char **params,
				 int fd_client, char is_connect)
{
  int	j;

  j = 0;
  if (params[1] == NULL)
    return (false);
  while (j < MAX_FD && strcmp(server->chans[i], params[1]) != 0)
    j++;
  if (j == MAX_FD)
    return (false);
  server->chans[j].users[fd_client] = is_connect;
  return (true);
}

bool	join_channel(t_server *server, char **params, int fd_client)
{
  return (co_deco_channel(server, params, fd_client, 1));
}

bool	leave_channel(t_server *server, char **params, int fd_client)
{
  return (co_deco_channel(server, params, fd_client, 0));
}