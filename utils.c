/*
** utils.c for tetris in /home/rectoria/delivery/Projets/PSU_2016_tetris
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Feb 20 17:49:11 2017 Bastien
** Last update Mon Feb 27 16:10:54 2017 Bastien
*/

#include <stdlib.h>
#include "tetris.h"

char    *fill_str(char *str, int i)
{
  char  *dest;
  int   j;

  j = -1;
  if ((dest = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  while (str[++j])
    dest[j] = str[j];
  j--;
  while (++j < i)
    dest[j] = ' ';
  dest[j] = '\0';
  free(str);
  return (dest);
}

void	free_tab(char ***tab)
{
  int	i;

  i = -1;
  while (*tab && (*tab)[++i])
    free((*tab)[i]);
  free((*tab)[i]);
  if (*tab)
    free((*tab));
}

char	*spe_pure(char *s)
{
  if (s[0] == '"' || s[0] == '\'' || s[0] == '{')
    {
      s[my_strlen(s) - 1] = 0;
      s += 1;
    }
  return (s);
}

int	my_help()
{
  my_putstr("Usage: ./tetris [options]\nOptions:\n");
  my_putstr("\t--help\t\t\tDisplay this help\n\t-l --level");
  my_putstr("={num}\tStart Tetris at level num (def: 1)\n");
  my_putstr("\t-kl --key-left={K}\tMove the tetrimino");
  my_putstr("LEFT using the K key (def: left arrow)\n");
  my_putstr("\t-kr --key-right={K}\tMove the tetrimino");
  my_putstr("RIGHT using the K key (def: right arrow)\n");
  my_putstr("\t-kt --key-turn={K}\tTURN the tetrimino");
  my_putstr("clockwise 90d using the K key (def: top arrow)\n");
  my_putstr("\t-kd --key-down={K}\tDROP the tetrimino");
  my_putstr("using the K key (def: down arrow)\n");
  my_putstr("\t-kq --key-quit={K}\tQUIT the tetrimino");
  my_putstr("using the K key (def: 'Q' key)\n");
  my_putstr("\t-kp --key-drop={K}\tPAUSE/RESTART the game");
  my_putstr("using the K key (def: space bar)\n");
  my_putstr("\t--map-size={row,col}\tSet the numbers of ");
  my_putstr("rows and columns of the map (def: 20,10)\n");
  my_putstr("\t-w --without-next\tHide next tetrimino (def: ");
  my_putstr("false)\n\t-d --debug\t\tDebug mode (def: false)\n");
  exit(0);
}
