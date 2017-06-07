/*
** orders.h for orders in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc/Server/src
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Jun  3 11:08:29 2017 Thomas LE MOULLEC
** Last update Wed Jun  7 22:09:46 2017 Leo Le Diouron
*/

#include "server.h"

bool            connection(t_server *, char **, int);
bool            check_user(t_server *, char **, int);
bool            list_channel(t_server *, char **, int);
bool            list_users(t_server *, char **, int);
bool            list_users_in_channel(t_server *, char **, int);
bool            join_channel(t_server *, char **, int);
bool            leave_channel(t_server *, char **, int);
bool            send_message(t_server *, char **, int);
bool		send_message_spe_user(t_server *, char **, int);
bool            receive_file(t_server *, char **, int);
bool		quit(t_server *, char **, int);

t_orders                     orders[] =
  {
    {NICK, &connection},
    {USER, &check_user},
    {LIST, &list_channel},
    {USERS, &list_users},
    {NAMES, &list_users_in_channel},
    {JOIN, &join_channel},
    {PART, &leave_channel},
    {MSG, &send_message},
    {PRIVMSG, &send_message_spe_user},
    {ACCEPT, &receive_file},
    {QUIT, &quit},
  };
