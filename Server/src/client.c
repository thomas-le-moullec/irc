/*
** client.c for client in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun May 28 15:40:43 2017 Thomas LE MOULLEC
** Last update Wed Jun  7 20:18:51 2017 Thomas LE MOULLEC
*/

#include "server.h"
#include "orders.h"

void		client_write(t_server *server, int fd)
{
  int		i;
  int		j;

  j = 0;
  while (server->users[fd].msg.queue[j][0] != '\0')
    {
      i = 0;
      if (write(fd, server->users[fd].msg.queue[j],
		strlen(server->users[fd].msg.queue[j])) == -1)
	printf("write fail\n");
      while (i < MAX_CHAR)
	{
	  server->users[fd].msg.queue[j][i] = 0;
	  i++;
	}
    }
  server->users[fd].msg.is_empty = true;
}

int		parse_cmd(t_server *server, int fd, char *line)
{
  int		i;
  char		**cmd;

  i = 0;
  cmd = my_str_to_wordtab(line, ' ');
  if (strcmp("QUIT", cmd[0]) == 0)
    close(fd);
  while (i < NBR_CMD)
    {
      if (strcmp(orders[i].cmd, cmd[0]) == 0)
	{
	  (orders[i].func)(server, cmd, fd);
	  break ;
	}
      i++;
    }
  if (i == NBR_CMD)
    send_message_all_users(server, line, fd);
  free_tab(cmd);
  return (0);
}

void		client_read(t_server *server, int fd)
{
  int		i;
  int		r;
  char		buf[512];
  char		**lines;

  i = 0;
  r = read(fd, buf, 512);
  if (r > 0)
    {
      buf[r] = '\0';
      if ((lines = get_orders(buf)) == NULL)
	return ;
      while (lines[i] != NULL)
	{
	  dprintf(fd, "001 Welcome !\r\n");
	  parse_cmd(server, fd, lines[i]);
	  i++;
	}
      free_tab(lines);
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
}
