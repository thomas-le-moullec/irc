/*
** server.h for server in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun May 28 14:16:12 2017 Leo Le Diouron
** Last update Sat Jun  3 15:10:03 2017 Leo Le Diouron
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
#define SIZE_MSG 10
#define SIZE_USERNAME 64
#define MAX_CHAR 512

#define NBR_CMD 8

#define NICK "NICK"
#define LIST "LIST"
#define JOIN "JOIN"
#define PART "PART"
#define USERS "USERS"
#define NAMES "NAMES"
#define MSG "MSG"
#define ACCEPT "ACCEPT_FILE"

#define SEP1 '\n'

#define LOCALHOST "127.0.0.1"

typedef enum
  {
    false,
    true
  } bool;

typedef void(*fct)();

typedef struct		s_msg
{
  char			queue[SIZE_MSG][MAX_CHAR];
  bool			is_empty;
}			t_msg;

typedef struct		s_env
{
  char			fd_type[MAX_FD];
  fct			fct_read[MAX_FD];
  fct			fct_write[MAX_FD];
  int			port;
}			t_env;

typedef struct		s_user
{
  char			nickname[SIZE_USERNAME];
  t_msg			msg;
}			t_user;

typedef struct		s_chan
{
  char			name[SIZE_USERNAME];
  char			users[MAX_FD];
}	 		t_chan;

typedef struct		s_server
{
  int			fd_max;
  t_chan		chans[MAX_FD];
  t_user		users[MAX_FD];
  int			fd;
  char			*ip;
  t_env			e;
  struct timeval	tv;
  fd_set		fd_read;
  fd_set		fd_write;
}			t_server;

typedef struct		s_orders
{
  char			*cmd;
  bool			(*func)(t_server *, char **, int);
}			t_orders;

t_user		*add_user(t_user *, char *, int, t_chan *);
t_chan		*add_channel(t_chan *, char *, t_user *);
void            initialise_server(t_server *, char *);
void            set_fds(t_server *);
void            run_server(t_server *);
void            add_server(t_server *);
void		add_client(t_server *, int);
void            server_read(t_server *, int);
void            server_write(t_server *, int);
void            client_read(t_server *, int);
char		**get_orders(char *);
char		*fill_order(char *, int *, char);
int		loop_on_char(char *, int, char);
void		*free_tab(char **);
bool		send_message_all_users(t_server *, char *, int);
char		**my_str_to_wordtab(char *, char);

#endif
