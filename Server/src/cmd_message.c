/*
** cmd_message.c for cmd_message in /home/le-dio_l/PSU_2016_myirc/Server/src
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Jun  3 10:33:49 2017 Leo Le Diouron
** Last update Sat Jun  3 15:14:01 2017 Leo Le Diouron
*/

#include "server.h"

bool	receive_file(t_server *server, char **params, int fd_client)
{
  (void)server;
  (void)params;
  (void)fd_client;
  return (true);
}

bool	send_message_all_users(t_server *server, char *message, int fd_client)
{
  int	i;
  int	j;
  int	k;
  int	l;

  j = 0;
  while (j < MAX_FD)
    {
      i = 0;
      if (server->chans[j].users[fd_client] == 1)
	while (i < MAX_FD)
	  {
	    k = 0;
	    if (server->chans[j].users[i] == 1 && i != fd_client)
	      {
		l = 0;
		while (l < SIZE_MSG && server->users[i].msg.queue[l][0] != '\0')
		  l++;
		if (l != SIZE_MSG)
		  while (message[k] != '\0')
		    {
		      server->users[i].msg.queue[l][k] = message[k];
		      server->users[i].msg.is_empty = false;
		      k++;
		    }
	      }
	    i++;
	  }
      j++;
    }
  return (true);
}

bool	send_message_spe_user(t_server *server, char **params, int fd_client)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  (void)fd_client;
  while (i < MAX_FD && strcmp(server->users[i].nickname, params[1]) != 0)
    i++;
  if (i == MAX_FD)
    return (false);
  while (k < SIZE_MSG && server->users[i].msg.queue[k][0] != '\0')
    k++;
  if (k != SIZE_MSG)
    while (params[2][j] != '\0')
      {
	server->users[i].msg.queue[k][j] = params[2][j];
	j++;
      }
  server->users[i].msg.is_empty = false;
  return (true);
}

bool	send_file(t_server *server, char **params, int fd_client)
{
  (void)server;
  (void)params;
  (void)fd_client;
  return (true);
}

bool	send_message(t_server *server, char **params, int fd_client)
{
  if (params[1] != NULL && params[2] != NULL && params[3] == NULL)
    return (send_message_spe_user(server, params, fd_client));
  if (params[1] != NULL && params[2] != NULL && params[3] != NULL)
    return (send_file(server, params, fd_client));
  return (false);
}
