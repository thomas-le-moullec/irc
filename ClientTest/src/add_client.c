/*
** add_client.c for add_client in /home/le-dio_l/PSU_2016_myirc/ClientTest
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun Jun  4 10:02:09 2017 Leo Le Diouron
** Last update Fri Jun  9 10:30:34 2017 Leo Le Diouron
*/

#include "client.h"

char			*modify_cmd(char *str)
{
  int			i;

  i = 0;
  str = &str[1];
  while (str[i] != '\0' && str[i] != ' ')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      i++;
    }
  return (str);
}

void			client_read(t_client *client)
{
  char			buf[512];
  char			**cmds;
  int			r;

  (void)client;
  printf("Reading !\n");
  r = read(1, buf, 511);
  buf[r] = '\0';
  cmds = my_str_to_wordtab(buf, ' ');
  printf("AAA : [%s]\n", cmds[0]);
  if (strncmp(cmds[0], "/Server", 7) == 0)
    {
      printf("BBB\n");
      add_server(client, cmds);
    }
  else
    write(client->fd, modify_cmd(buf), strlen(buf) - 1);
}

void			client_write(t_client *client)
{
  (void)client;
  printf("Writing !\n");
}

void                    add_client(t_client *client)
{
  client->e.fd_type[0] = FD_CLIENT;
  client->e.fct_read[0] = client_read;
  client->e.fct_write[0] = client_write;
}
