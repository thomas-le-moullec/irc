/*
** server.c for server in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc/Server/src
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun May 28 14:41:53 2017 Thomas LE MOULLEC
** Last update Sun May 28 14:58:23 2017 Thomas LE MOULLEC
*/

#include "server.h"

void			add_server(t_env *e)
{
  int			s;
  struct sockaddr_in	sin;

  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    exit(ERROR);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  bind(s, (struct sockaddr*)&sin, sizeof(sin));
  listen(s, 42);
  e->fd_type[s] = FD_SERVER;
  e->fct_read[s] = server_read;
  e->fct_write[s] = NULL;
}

void			run_server(t_server *server)
{
  bool			end;

  while (end == false)
    {
      FD_ZERO(&server->fd_read);
      server->fd_max = 0;
    }
}
