/*
** client.c for client in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun May 28 15:40:43 2017 Thomas LE MOULLEC
** Last update Sat Jun  3 11:30:18 2017 Thomas LE MOULLEC
*/

#include "server.h"
#include "orders.h"

void		client_write(t_server *server, int fd)
{
  printf("%d\n", fd);
  if (write(fd, "a", 1) == -1)
    printf("write fail\n");
  server->e.msg[fd].is_empty = true;
  // Réponse aux server.
}

void		client_read(t_server *server, int fd)
{
  int		r;
  char		buf[512];
  char		**cmd;
  char		**lines;
  int		i;

  r = read(fd, buf, 512);
  if (r > 0)
    {
      buf[r] = '\0';
      if ((lines = get_orders(buf)) == NULL)
	return ;
      r = 0;
      while (lines[r] != NULL)
	{
	  i = 0;
	  if ((cmd = my_str_to_wordtab(lines[r], ' ')) == NULL)
	    {
	      free(lines);
	      return ;
	    }
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
	    send_message_all_users(server, lines[r], fd);
	  free_tab(cmd);
	  //if on a rien trouvé ; go $message
	  // faire les free
	  r++;
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
  printf("cs : %d\n", cs);
}
