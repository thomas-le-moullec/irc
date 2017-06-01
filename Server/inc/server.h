/*
** server.h for server in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun May 28 14:16:12 2017 Leo Le Diouron
** Last update Mon May 29 22:42:33 2017 Thomas LE MOULLEC
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
#define MAX_MSG 10
#define MAX_CHAR 512

#define LOCALHOST "127.0.0.1"

typedef enum
  {
    false,
        true
  } bool;

typedef void(*fct)();

struct			s_chan;
struct  		s_user;

typedef struct		s_msg
{
  char			queue[MAX_MSG][MAX_CHAR];
  bool			is_empty;
}			t_msg;

typedef struct		s_env
{
  char			fd_type[MAX_FD];
  fct			fct_read[MAX_FD];
  fct			fct_write[MAX_FD];
  int			port;
  t_msg			msg[MAX_FD];
}			t_env;

typedef struct		s_user
{
  char			*nickname;
  int			fd;
  struct s_chan		chans[MAX_FD];
}			t_user;

typedef struct		s_chan
{
  char			*name;
  struct s_user		users[MAX_FD];
}	 		t_chan;

typedef struct		s_server
{
  int			fd_max;
  t_chan		chan[MAX_FD];
  t_user		users[MAX_FD];
  int			fd;
  char			*ip;
  t_env			e;
  struct timeval	tv;
  fd_set		fd_read;
  fd_set		fd_write;
}			t_server;

t_user		*add_user(t_user *, char *, int, t_chan *);
t_chan		*add_channel(t_chan *, char *, t_user *);
void            initialise_server(t_server *, char *);
void            set_fds(t_server *);
void            run_server(t_server *);
void            add_server(t_env *);
void		add_client(t_env *, int);
void            server_read(t_env *, int);
void            server_write(t_env *, int);
void            client_read(t_env *, int);

#endif
