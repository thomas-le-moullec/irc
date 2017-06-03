/*
** orders.h for orders in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc/Server/src
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat Jun  3 11:08:29 2017 Thomas LE MOULLEC
** Last update Sat Jun  3 11:08:37 2017 Thomas LE MOULLEC
*/

#include "server.h"

bool            connection(t_server *, char **, int);
bool            list_channel(t_server *, char **, int);
bool            list_users(t_server *, char **, int);
bool            list_users_in_channel(t_server *, char **, int);
bool            join_channel(t_server *, char **, int);
bool            leave_channel(t_server *, char **, int);
bool            send_message(t_server *, char **, int);
bool            receive_file(t_server *, char **, int);

t_orders                     orders[] =
  {
    {NICK, &connection},
    {LIST, &list_channel},
    {USERS, &list_users},
    {NAMES, &list_users_in_channel},
    {JOIN, &join_channel},
    {PART, &leave_channel},
    {MSG, &send_message},
    {ACCEPT, &receive_file},
  };
