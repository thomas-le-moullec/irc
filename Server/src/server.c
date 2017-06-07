/*
** server.c for server in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc/Server/src
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun May 28 14:41:53 2017 Thomas LE MOULLEC
** Last update Mon Jun  5 22:14:18 2017 Leo Le Diouron
*/

#include "server.h"

void			server_read(t_server *server, int fd)
{
  add_client(server, fd);
}

void			server_write(t_server *server, int fd)
{
  (void)server;
  if (write(fd, "a", 1) == -1)
    exit(ERROR);
}

void			add_server(t_server *server)
{
  int			s;
  struct sockaddr_in	sin;

  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    {
      printf("Socket error\n");
      exit(ERROR);
    }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(server->e.port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    printf("Cannot bind\n");
  listen(s, MAX_FD);
  server->e.fd_type[s] = FD_SERVER;
  server->e.fct_read[s] = server_read;
  server->e.fct_write[s] = server_write;
}

void			get_order(t_server *server)
{
  int			i;

  i = 0;
  while (i < MAX_FD)
    {
      if (FD_ISSET(i, &server->fd_read) && server->e.fd_type[i] != FD_FREE)
	server->e.fct_read[i](server, i);
      if (FD_ISSET(i, &server->fd_write) && server->e.fd_type[i] != FD_FREE)
	server->e.fct_write[i](server, i);
      i++;
    }
}

void			run_server(t_server *server)
{
  bool			end;

  end = false;
  while (end == false)
    {
      FD_ZERO(&server->fd_read);
      FD_ZERO(&server->fd_write);
      server->fd_max = 0;
      set_fds(server);
      if (select(server->fd_max + 1, &server->fd_read,
		 NULL, NULL, &server->tv) == -1)
	perror("select");
      get_order(server);
    }
}
