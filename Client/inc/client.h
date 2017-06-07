/*
** client.h for client in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat May 27 16:25:29 2017 Thomas LE MOULLEC
** Last update Sun Jun  4 10:48:10 2017 Leo Le Diouron
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <ctype.h>

#define ERROR 84
#define SUCCESS 0

#define READ_SIZE 1024

#define CRLF1 '\r'
#define CRLF2 '\n'

#define SERVER "/server"
#define ERR_CONNECT "Please use '/server $host[:$port]' to connect\r\n"

typedef enum
  {
    false,
        true
  } bool;

typedef struct	s_client
{
  char		buff[1024];
  bool		is_connected;
  int		fd;
}		t_client;

void		run_client();
bool		read_client(t_client *);
bool		get_order(t_client *);
bool		connect_to_server(char **, t_client *);
bool		send_to_server(char *, int);
bool            check_params(char **);
char		**my_str_to_wordtab(char *, char);
char            **my_str_to_wordtab(char *, char);

#endif
