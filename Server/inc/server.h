/*
** server.h for server in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat May 27 16:26:07 2017 Thomas LE MOULLEC
** Last update Sat May 27 17:00:48 2017 Thomas LE MOULLEC
*/

#ifndef SERVER_H_
# define SERVER_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FD_FREE	0
#define FD_CLIENT 1
#define FD_SERVER 2

#define MAX_FD 255

typedef void(*fct)();

typedef struct		s_env
{
  char			fd_type[MAX_FD];
  fct			fct_read[MAX_FD];
  fct			fct_write[MAX_FD];
}			t_env;

typedef struct		s_server
{
  //  t_chan		*chan;
  //  t_users		*users;
  int			fd;
  int			port;
  char			*ip;
  t_env			*e;
  struct timeval	tv;
  fd_set		fd_read;
}		t_server;

#endif
