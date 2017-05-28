/*
** initialisation.c for initialisation in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc/Server/src
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sun May 28 14:33:40 2017 Thomas LE MOULLEC
** Last update Sun May 28 14:48:17 2017 Thomas LE MOULLEC
*/

#include "server.h"

void		initiliase_server(t_server *server, char *port)
{
  server->chan = NULL;
  server->users = NULL;
  server->fd = 0;
  server->e.port = atoi(port);
  server->ip = LOCALHOST;
  server->tv.tv_sec = 20;
  server->tv.tv_usec = 0;
  FD_ZERO(&server->fd_read);
  memset(server->e.fd_type);
  add_server(&server->e);
}
