/*
** main.c for main in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat May 27 16:26:33 2017 Thomas LE MOULLEC
** Last update Sat May 27 18:02:33 2017 Leo Le Diouron
*/

#include "server.h"

int		main(int ac, char **av)
{
  t_user	*users;
  t_user	*new_user;

  if (ac == 2 && strcmp(av[1], "--help") == 0)
    {
      printf("USAGE ./server port\n");
      return (0);
    }
  users = NULL;
  if ((new_user = malloc(sizeof(*new_user))) == NULL)
    exit(84);
  new_user->nickname = strdup("Leo");
  new_user->fd = 1;
  new_user->chans = NULL;
  users = add_user(users, "Thomas", 1, NULL);
  new_user->fd = 3;
  users = add_user(users, "Leo", 3, NULL);
  return (0);
}
