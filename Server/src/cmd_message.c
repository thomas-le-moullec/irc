/*
** cmd_message.c for cmd_message in /home/le-dio_l/PSU_2016_myirc/Server/src
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Jun  3 10:33:49 2017 Leo Le Diouron
** Last update Mon Jun 12 13:48:42 2017 Leo Le Diouron
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

  i = 0;
  j = server->users[fd_client].last_chan;
  if (j != -1)
    {
      while (i < MAX_FD)
	{
	  if (server->chans[j].users[i] == 1 && i != fd_client)
	    fill_queue(server, i, message);
	  i++;
	}
      return (true);
    }
  return (false);
}

bool	send_message_spe_user(t_server *server, char **params, int fd_client)
{
  int	i;

  i = 0;
  (void)fd_client;
  while (i < MAX_FD && strcmp(server->users[i].nickname, params[1]) != 0)
    i++;
  if (i == MAX_FD)
    {
      dprintf(fd_client, PRIVMSG_NO_USER);
      return (false);
    }
  fill_queue(server, i, params[2]);
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
