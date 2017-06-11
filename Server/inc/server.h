/*
** server.h for server in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun May 28 14:16:12 2017 Leo Le Diouron
** Last update Sun Jun 11 15:08:48 2017 Leo Le Diouron
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
#include <ctype.h>

#define FD_FREE	0
#define FD_CLIENT 1
#define FD_SERVER 2

#define SUCCESS 0
#define ERROR 84

#define MAX_FD 255
#define SIZE_MSG 10
#define SIZE_USERNAME 64
#define MAX_CHAR 512

#define NBR_CMD 11

#define NICK "NICK"
#define USER "USER"
#define LIST "LIST"
#define JOIN "JOIN"
#define PART "PART"
#define USERS "USERS"
#define NAMES "NAMES"
#define MSG "MSG"
#define PRIVMSG "PRIVMSG"
#define ACCEPT "ACCEPT_FILE"
#define QUIT "QUIT"

#define WELCOME "001 Welcome\r\n"
#define TOPIC "332 Topic\r\n"
#define CHAN_BEGIN "321 begin of channels\r\n"
#define CHAN_END "323 end of channels\r\n"
#define LIST_BEGIN "392 begin of users\r\n"
#define LIST_NO_USER "394 no users\r\n"
#define LIST_END "395 end of users\r\n"
#define NAMES_END "366 end of names\r\n"
#define PRIVMSG_NO_USER "301 User doesn't exist\r\n"

#define SOCKET_ERROR "Socket error\n"
#define CANNOT_BIND "Cannot bind\n"

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
  bool			is_activated;
  int			last_chan;
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
void		fill_queue(t_server *, int, char *);
int             parse_cmd(t_server *, int, char *);
char            *upper_str(char *);

#endif
