/*
** cmd_list.c for cmd_list in /home/le-dio_l/PSU_2016_myirc/Server/src
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sat Jun  3 10:00:10 2017 Leo Le Diouron
** Last update Sat Jun  3 10:21:46 2017 Leo Le Diouron
*/

#include "server.h"

bool	list_channels(t_server *server, char **params, int fd_client)
{
  int	i;

  (void)fd_client;
  i = 0;
  while (i < MAX_FD)
    {
      if ((params[1] == NULL) ||
	  (params[1] != NULL &&
	   strstr(server->chans[i].name, params[1]) != NULL))
	if (server->chans[i].name[0] != '\0')
	  printf("channel : %s", server->chans[i].name);
      i++;
    }
  return (true);
}

bool	list_users(t_server *server, char **params, int fd_client)
{
  int   i;

  (void)params;
  (void)fd_client;
  i = 0;
  while (i < MAX_FD)
    {
      if (server->users[i].nickname[0] != '\0')
	printf("users : %s", server->users[i].nickname);
      i++;
    }
  return (true);
}

bool	list_users_in_channel(t_server *server, char **params, int fd_client)
{
  int	i;
  int	j;

  (void)fd_client;
  i = 0;
  j = 0;
  while (j < MAX_FD && strcmp(server->chans[j].nickname, params[1]) != 0)
    j++;
  if (j == MAX_FD)
    return (false);
  while (i < MAX_FD)
    {
      if (server->chans[j].users[i] == 1)
	printf("users in channel : %s\n", server->users[i].nickname);
      i++;
    }
  return (true);
}
