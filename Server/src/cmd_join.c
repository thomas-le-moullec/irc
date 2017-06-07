/*
** cmd_join.c for cmd_join in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed Jun  7 21:19:59 2017 Leo Le Diouron
** Last update Wed Jun  7 22:15:11 2017 Leo Le Diouron
*/

#include "server.h"

int	new_channel(t_server *server, char **params)
{
  int	j;
  int	i;

  j = 0;
  i = -1;
  while (j < MAX_FD && server->chans[j].name[0] != '\0')
    j++;
  if (j == MAX_FD)
    return (-1);
  while (params[1][++i] != '\0')
    server->chans[j].name[i] = params[1][i];
  return (j);
}

bool    authentification_channel(t_server *server, char **params,
				 int fd_client, char is_connect)
{
  int   j;

  j = 0;
  if (params[1] == NULL)
    return (false);
  while (j < MAX_FD && strcmp(server->chans[j].name, params[1]) != 0)
    j++;
  if (j == MAX_FD && is_connect == 1)
    j = new_channel(server, params);
  if (j == -1 || (j == MAX_FD && is_connect == 0))
    return (false);
  server->chans[j].users[fd_client] = is_connect;
  if (is_connect == 1)
    dprintf(fd_client, TOPIC);
  return (true);
}

bool    join_channel(t_server *server, char **params, int fd_client)
{
  return (authentification_channel(server, params, fd_client, 1));
}

bool    leave_channel(t_server *server, char **params, int fd_client)
{
  return (authentification_channel(server, params, fd_client, 0));
}
