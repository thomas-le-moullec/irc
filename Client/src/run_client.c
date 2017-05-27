/*
** run_client.c for run_client in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat May 27 17:09:26 2017 Thomas LE MOULLEC
** Last update Sat May 27 18:37:54 2017 Thomas LE MOULLEC
*/

#include "client.h"

bool		read_client(t_client *client)
{
  int		size;

  size = -1;
  if ((size = read(0, client->buff, READ_SIZE - 1)) <= 0)
    return (false);
  client->buff[size] = 0;
  return (true);
}

void		run_client()
{
  bool		end;
  t_client	client;

  end = false;
  client.is_connected = false;
  client.fd = 0;
  while (end == false)
    {
      memset(&client.buff, 0, READ_SIZE);
      if (read_client(&client) == false)
	end = true;
      else
	get_order(&client);
    }
  close(client.fd);
}
