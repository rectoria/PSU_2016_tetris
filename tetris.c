/*
** tetris.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Feb 20 12:18:30 2017 Bastien
** Last update Mon Feb 27 19:05:39 2017 Thibaut Cornolti
*/

#include "tetris.h"

int		main(int ac, char **av)
{
  t_pars	p;
  t_shapes	*s;

  (void) ac;
  my_super_parser(&p, av);
  get_tetrimino(&s);
  if (p.d)
    debug(&p, s);
  return (0);
}
