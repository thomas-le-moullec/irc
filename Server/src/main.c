/*
** main.c for main in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat May 27 16:26:33 2017 Thomas LE MOULLEC
** Last update Sun May 28 14:01:52 2017 Leo Le Diouron
*/

#include "server.h"

int		main(int ac, char **av)
{
  t_user	*users;
  t_chan	*chans;

  if (ac == 2 && strcmp(av[1], "--help") == 0)
    {
      printf("USAGE ./server port\n");
      return (0);
    }
  users = NULL;
  chans = NULL;
  users = add_user(users, "Thomas", 1, NULL);
  users = add_user(users, "Leo", 3, NULL);
  chans = add_channel(chans, "chan1", users);
  printf("nom[1] -> %s, nom[2] -> %s\n", chans->name, chans->users->next->nickname);
  return (0);
}
