/*
** run_client.c for run_client in /home/le-dio_l/PSU_2016_myirc/ClientTest
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun Jun  4 09:59:18 2017 Leo Le Diouron
** Last update Mon Jun  5 11:05:52 2017 Leo Le Diouron
*/

#include "client.h"

void			server_read(t_client *client)
{
  char			buf[512];

  (void)client;
  read(client->fd, buf, 512);
  printf("reading server : %s!\n", buf);
}

void			server_write(t_client *client)
{
  (void)client;
  printf("writing server !\n");
}

void			add_server(t_client *client, char **cmd)
{
  char                  *ip;
  int                   port;
  struct protoent       *pe;
  struct sockaddr_in    s_in;

  printf("On add un server !\n");
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
  client->e.fd_type[client->fd] = FD_SERVER;
  client->e.fct_read[client->fd] = server_read;
  client->e.fct_write[client->fd] = server_write;
}

void                    get_order(t_client *client)
{
  int                   i;

  i = 0;
  while (i < MAX_FD)
    {
      if (FD_ISSET(i, &client->fd_read))
	client->e.fct_read[i](client, i);
      if (FD_ISSET(i, &client->fd_write))
	client->e.fct_write[i](client, i);
      i++;
    }
}

void                    run_client(t_client *client)
{
  bool                  end;

  end = false;
  while (end == false)
    {
      FD_ZERO(&client->fd_read);
      FD_ZERO(&client->fd_write);
      client->fd_max = 0;
      set_fds(client);
      if (select(client->fd_max + 1, &client->fd_read,
		 NULL, NULL, &client->tv) == -1)
	perror("select");
      get_order(client);
    }
}
