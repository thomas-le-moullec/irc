/*
** cmd_message.c for cmd_message in /home/le-dio_l/PSU_2016_myirc/Server/src
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Jun  3 10:33:49 2017 Leo Le Diouron
** Last update Sat Jun  3 10:52:57 2017 Leo Le Diouron
*/

#include "server.h"

bool	send_message_all_users(t_server *server, char *message, int fd_client)
{
  int	i;
  int	j;

  j = 0;
  while (j < MAX_FD)
    {
      i = 0;
      if (server->chans[j].users[fd_client] == 1)
	while (i < MAX_FD)
	  {
	    if (server->chans[j].users[i] == 1 && i != fd_client)
	      server->e.msg[i].queue[0] = message;
	    i++;
	  }
      j++;
    }
  return (true);
}

bool	send_message_spe_user(t_server *server, char **params, int fd_client)
{
  int	i;

  i = 0;
  while (i < MAX_FD && strcmp(server->users[i], params[1]) == 0)
    i++;
  if (i == MAX_FD)
    return (false);
  server->e.msg[i].queue[0] = params[2];
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
  if (params[0] != NULL && params[1] == NULL)
    return (send_message_all_users(server, params[0], fd_client));
  if (params[1] != NULL && params[2] != NULL && params[3] == NULL)
    return (send_message_spe_user(server, params, fd_client));
  if (params[1] != NULL && params[2] != NULL && params[3] != NULL)
    return(send_file(server, params, fd_client));
  return (false);
}
