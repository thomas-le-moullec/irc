/*
** cmd_list.c for cmd_list in /home/le-dio_l/PSU_2016_myirc/Server/src
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Jun  3 10:00:10 2017 Leo Le Diouron
** Last update Wed Jun  7 22:27:54 2017 Leo Le Diouron
*/

#include "server.h"

bool	list_channel(t_server *server, char **params, int fd_client)
{
  int	i;

  i = 0;
  dprintf(fd_client, CHAN_BEGIN);
  while (i < MAX_FD)
    {
      if ((params[1] == NULL) ||
	  (params[1] != NULL &&
	   strstr(server->chans[i].name, params[1]) != NULL))
	{
	  if (server->chans[i].name[0] != '\0')
	    dprintf(fd_client, "322 %s\r\n", server->chans[i].name);
	}
      i++;
    }
  dprintf(fd_client, CHAN_END);
  return (true);
}

bool	list_users(t_server *server, char **params, int fd_client)
{
  int   i;
  bool	have_user;

  (void)params;
  i = 0;
  have_user = false;
  dprintf(fd_client, LIST_BEGIN);
  while (i < MAX_FD)
    {
      if (server->users[i].nickname[0] != '\0')
	{
	  dprintf(fd_client, "393 %s\n", server->users[i].nickname);
	  have_user = true;
	}
      i++;
    }
  if (have_user == false)
    dprintf(fd_client, LIST_NO_USER);
  dprintf(fd_client, LIST_END);
  return (true);
}

bool	list_users_in_channel(t_server *server, char **params, int fd_client)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (params[1] == NULL)
    return (false);
  while (j < MAX_FD && strcmp(server->chans[j].name, params[1]) != 0)
    j++;
  if (j == MAX_FD)
    return (false);
  while (i < MAX_FD)
    {
      if (server->chans[j].users[i] == 1)
	dprintf(fd_client, "353 %s\r\n", server->users[i].nickname);
      i++;
    }
  dprintf(fd_client, NAMES_END);
  return (true);
}
