/*
** handle_server.c for handle_server in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat May 27 18:04:57 2017 Thomas LE MOULLEC
** Last update Sat May 27 18:56:52 2017 Thomas LE MOULLEC
*/

#include "client.h"

bool		send_to_server(char *buf, int fd)
{
  printf("SENDiNG !\n");
  dprintf(fd, buf);
  return (true);
}

bool			check_params(char **cmd)
{
  if (cmd[1] == NULL || cmd[2] == NULL)
    return (false);
  return (true);
}

bool			connect_to_server(char **cmd, t_client *client)
{
  char			*ip;
  int			port;
  struct protoent	*pe;
  struct sockaddr_in    s_in;

  if (check_params(cmd) == false)
    {
      printf(ERR_CONNECT);
      return (false);
    }
  ip = cmd[1];
  port = atoi(cmd[2]);
  pe = getprotobyname("TCP");
  if (!pe || (client->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    exit(ERROR);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(ip);
  printf("Will try to connect to :---%s--- with port:---%d---\n", ip, port);
  if (connect(client->fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      printf("Error on Connect\n");
      exit(ERROR);
    }
  client->is_connected = true;
  return (true);
}
