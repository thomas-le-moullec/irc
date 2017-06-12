/*
** cmd_join.c for cmd_join in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Wed Jun  7 21:19:59 2017 Leo Le Diouron
** Last update Mon Jun 12 13:49:56 2017 Leo Le Diouron
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

void	define_last_channel(t_server *server, int num_chan,
			    int fd_client, char is_connect)
{
  int	i;

  i = -1;
  if (is_connect == 1)
    {
      server->users[fd_client].last_chan = num_chan;
      dprintf(fd_client, TOPIC);
    }
  else
    {
      while (++i < MAX_FD)
	if (server->chans[i].users[fd_client] == 1)
	  {
	    server->users[fd_client].last_chan = i;
	    break ;
	  }
      if (i == MAX_FD)
	server->users[fd_client].last_chan = -1;
    }
}

bool    authentification_channel(t_server *server, char **params,
				 int fd_client, char is_connect)
{
  int   j;
  char	*cmd;

  j = 0;
  if (params[1] == NULL)
    return (false);
  cmd = NULL;
  if ((cmd = malloc(strlen("NAMES ") + strlen(params[1]))) == NULL)
    exit(ERROR);
  cmd = strcpy(cmd, "NAMES ");
  cmd = strcat(cmd, params[1]);
  while (j < MAX_FD && strcmp(server->chans[j].name, params[1]) != 0)
    j++;
  if (j == MAX_FD && is_connect == 1)
    j = new_channel(server, params);
  if (j == -1 || (j == MAX_FD && is_connect == 0))
    return (false);
  server->chans[j].users[fd_client] = is_connect;
  define_last_channel(server, j, fd_client, is_connect);
  if (is_connect == 1)
    parse_cmd(server, fd_client, cmd);
  free(cmd);
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
