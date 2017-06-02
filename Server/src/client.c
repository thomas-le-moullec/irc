/*
** client.c for client in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun May 28 15:40:43 2017 Thomas LE MOULLEC
** Last update Thu Jun  1 20:38:52 2017 Leo Le Diouron
*/

#include "server.h"

void		client_write(t_env *e, int fd)
{
  printf("%d\n", fd);
  if (write(fd, "a", 1) == -1)
    printf("write fail\n");
  e->msg[fd].is_empty = true;
}

void		client_read(t_env *e, int fd)
{
  int		r;
  int		j;
  //  char		buf[4096];

  printf("Salut !\n");
  r = read(fd, e->msg[fd].queue[0], 512);
  j = 0;
  if (r > 0)
    {
      e->msg[fd].queue[0][r] = '\0';
      /*      printf("%d: %s\n", fd, buf);
      while (buf[j] != '\0')
	e->msg[fd].queue[0][j] = buf[j++];
	e->msg[fd].queue[0][j] = '\0';*/
      e->msg[fd].is_empty = false;
      printf(":: .%s.\n", e->msg[fd].queue[0]);
      // exec_order(buf, server, fd);
    }
  else
    {
      printf("%d: Connection closed\n", fd);
      close(fd);
      e->fd_type[fd] = FD_FREE;
    }
}

void			add_client(t_env *e, int s)
{
  int			cs;
  struct sockaddr_in	client_sin;
  socklen_t		client_sin_len;

  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
  e->fd_type[cs] = FD_CLIENT;
  e->fct_read[cs] = client_read;
  e->fct_write[cs] = client_write;
  printf("cs : %d\n", cs);
}
