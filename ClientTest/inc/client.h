/*
** client.h for client in /home/le-dio_l/PSU_2016_myirc/ClientTest
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun Jun  4 09:51:46 2017 Leo Le Diouron
** Last update Sun Jun  4 10:34:12 2017 Leo Le Diouron
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>

#define FD_FREE 0
#define FD_CLIENT 1
#define FD_SERVER 2

#define SUCCESS 0
#define ERROR 84

#define MAX_FD 255

typedef enum
  {
    false,
    true
  } bool;

typedef void(*fct)();

typedef struct          s_env
{
  char                  fd_type[MAX_FD];
  fct                   fct_read[MAX_FD];
  fct                   fct_write[MAX_FD];
  int                   port;
}                       t_env;

typedef struct          s_client
{
  int                   fd_max;
  int                   fd;
  char                  *ip;
  t_env                 e;
  struct timeval        tv;
  fd_set                fd_read;
  fd_set                fd_write;
}                       t_client;

void                    run_client(t_client *);
void                    add_server(t_client *, char **);
void			initialise_client(t_client *);
void			set_fds(t_client *);
void                    add_client(t_client *);

#endif
