/*
** get_order.c for get_order in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat May 27 17:40:06 2017 Thomas LE MOULLEC
** Last update Sat May 27 18:50:21 2017 Thomas LE MOULLEC
*/

#include "client.h"

bool		get_order(t_client *client)
{
  char		**cmd;

  if ((cmd = my_str_to_wordtab(client->buff, ' ')) == NULL)
    return (false);
  if (strcmp(cmd[0], SERVER) == 0 && client->is_connected == false)
    return (connect_to_server(cmd, client));
  else
    {
      if (client->is_connected == true)
	return (send_to_server(client->buff, client->fd));
      else
	printf(ERR_CONNECT);
    }
  return (false);
}
