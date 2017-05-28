/*
** server.h for server in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun May 28 14:16:12 2017 Leo Le Diouron
** Last update Sun May 28 14:16:13 2017 Leo Le Diouron
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

#define SUCCESS 0
#define ERROR 84

#define MAX_FD 255

typedef enum
  {
    false,
        true
  } bool;

typedef void(*fct)();

struct			s_chan;
struct  		s_user;

typedef struct		s_env
{
  char			fd_type[MAX_FD];
  fct			fct_read[MAX_FD];
  fct			fct_write[MAX_FD];
}			t_env;

typedef struct		s_chan
{
  char			*name;
  struct s_user		*users;
  struct s_chan		*next;
  struct s_chan		*prev;
}			t_chan;

typedef struct		s_user
{
  char			*nickname;
  int			fd;
  struct s_chan		*chans;
  struct s_user		*next;
  struct s_user		*prev;
}			t_user;

typedef struct		s_server
{
  t_chan		*chan;
  t_user		*users;
  int			fd;
  int			port;
  char			*ip;
  t_env			*e;
  struct timeval	tv;
  fd_set		fd_read;
}			t_server;

t_user		*add_user(t_user *, char *, int, t_chan *);
t_chan		*add_channel(t_chan *, char *, t_user *);

#endif
