/*
** add_client.c for add_client in /home/le-dio_l/PSU_2016_myirc/ClientTest
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun Jun  4 10:02:09 2017 Leo Le Diouron
** Last update Sun Jun  4 10:43:59 2017 Leo Le Diouron
*/

#include "client.h"

void			client_read(t_client *client)
{
  char			buf[512];
  int			r;

  (void)client;
  printf("Reading !\n");
  r = read(1, buf, 511);
  buf[r] = '\0';
  //add_server(client, NULL);
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
