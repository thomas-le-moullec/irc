/*
** main.c for main in /home/le-mou_t/rendu/TEK2/C/PSU_2016_myirc
** 
** Made by Thomas LE MOULLEC
** Login   <le-mou_t@epitech.net>
** 
** Started on  Sat May 27 16:26:33 2017 Thomas LE MOULLEC
** Last update Thu Jun  1 21:00:24 2017 Leo Le Diouron
*/

#include "server.h"

int		main(int ac, char **av)
{
  t_server	server;

  if (ac != 2)
    return (ERROR);
  if (ac == 2 && strcmp(av[1], "--help") == 0)
    {
      printf("USAGE ./server port\n");
      return (SUCCESS);
    }
  initialise_server(&server, av[1]);
  run_server(&server);
  return (SUCCESS);
}
