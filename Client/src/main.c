/*
** main.c for main in /home/le-dio_l/PSU_2016_myirc
** 
** Made by Leo Le Diouron
** Login   <le-dio_l@epitech.net>
** 
** Started on  Sun Jun  4 10:21:03 2017 Leo Le Diouron
** Last update Sun Jun  4 10:22:14 2017 Leo Le Diouron
*/

#include "client.h"

int		main(int ac, char **av)
{
  t_client	client;

  (void)ac;
  (void)av;
  initialise_client(&client);
  run_client(&client);
  return (0);
}
