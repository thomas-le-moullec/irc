/*
** cmd_connection.c for cmd_connection in /home/le-dio_l/PSU_2016_myirc/Server/src
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Jun  3 10:23:04 2017 Leo Le Diouron
** Last update Mon Jun  5 11:17:29 2017 Leo Le Diouron
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
  return (true);
}

bool	authentification_channel(t_server *server, char **params,
				 int fd_client, char is_connect)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  if (params[1] == NULL)
    return (false);
  while (j < MAX_FD && strcmp(server->chans[j].name, params[1]) != 0)
    j++;
  if (j == MAX_FD && is_connect == 1)
    {
      j = 0;
      while (j < MAX_FD && server->chans[j].name[0] != '\0')
	j++;
      if (j == MAX_FD)
	return (false);
      while (params[1][++i] != '\0')
	server->chans[j].name[i] = params[1][i];
    }
  if (j == MAX_FD && is_connect == 0)
    return (false);
  server->chans[j].users[fd_client] = is_connect;
  return (true);
}

bool	join_channel(t_server *server, char **params, int fd_client)
{
  return (authentification_channel(server, params, fd_client, 1));
}

bool	leave_channel(t_server *server, char **params, int fd_client)
{
  return (authentification_channel(server, params, fd_client, 0));
}
