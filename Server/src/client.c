/*
** client.c for client in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun May 28 15:40:43 2017 Thomas LE MOULLEC
** Last update Sat Jun  3 09:36:58 2017 Leo Le Diouron
*/

#include "server.h"

void		client_write(t_server *server, int fd)
{
  printf("%d\n", fd);
  if (write(fd, "a", 1) == -1)
    printf("write fail\n");
  server->e.msg[fd].is_empty = true;
}

void		client_read(t_server *server, int fd)
{
  int		r;
  int		j;
  char		buf[4096];

  r = read(fd, buf, 512);
  j = 0;
  if (r > 0)
    {
      buf[r] = '\0';
      // exec_order(buf, server, fd);
    }
  else
    {
      printf("%d: Connection closed\n", fd);
      close(fd);
      server->e.fd_type[fd] = FD_FREE;
    }
}

void			add_client(t_server *server, int s)
{
  int			cs;
  struct sockaddr_in	client_sin;
  socklen_t		client_sin_len;

  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
  server->e.fd_type[cs] = FD_CLIENT;
  server->e.fct_read[cs] = client_read;
  server->e.fct_write[cs] = client_write;
  printf("cs : %d\n", cs);
}
