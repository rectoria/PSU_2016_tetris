/*
** tetramino.c for tetris in /home/rectoria/delivery/Projets/CPE_2016_matchstick
** 
** Made by Bastien
** Login   <rectoria@epi%tech.net>
** 
** Started on  Mon Feb 20 13:24:10 2017 Bastien
** Last update Mon Feb 20 19:08:43 2017 Bastien
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include "tetris.h"

void		put_structab(t_shapes ***shapes, t_shapes *piece, int size)
{
  t_shapes	**tab;
  int		i;

  i = (!*shapes) ? 0 : -1;
  if ((tab = malloc(sizeof(t_shapes *) * (size + 1))) == NULL)
    return ;
  while ((*shapes) && (*shapes)[++i])
    tab[i] = (*shapes)[i];
  tab[i] = piece;
  tab[i + 1] = NULL;
  free(*shapes);
  (*shapes) = tab;
}

void	get_size(t_shapes *piece, char *first_line)
{
  char	**tab;
  char	*str;

  tab = my_strsplit(first_line, ' ');
  piece->width = my_getnbr(tab[0]);
  piece->height = my_getnbr(tab[1]);
  piece->color = my_getnbr(tab[2]);
  free_tab(&tab);
}

void	add_shape(t_shapes ***shapes, int fd)
{
  t_shapes	*piece;
  char		*str;
  char		*temp;
  char		*antileak;
  static int	size = 1;

  str = NULL;
  if ((piece = malloc(sizeof(t_shapes))) == NULL)
    return ;
  get_size(piece, get_next_line(fd));
  while ((temp = get_next_line(fd)) != NULL)
    {
      antileak = my_strmcat(str, "@");
      free(str);
      str = my_strmcat(antileak, temp);
      free(temp);
      free(antileak);
    }
  piece->map = my_strsplit(str, '@');
  put_structab(shapes, piece, size);
  free(str);
  size += 1;
}

void		get_tetrimino(t_shapes ***shapes)
{
  DIR		*directory;
  struct dirent	*file;
  int		fd;

  directory = opendir("./tetriminoes");
  while ((file = readdir(directory)) != NULL)
    {
      if (file->d_name[0] != '.')
	{
	  if ((fd = open(my_strmcat("./tetriminoes/", file->d_name), O_RDONLY)) == -1)
	    return ;
	  add_shape(shapes, fd);
	}
      close(fd);
    }
  closedir(directory);
}

int	main()
{
  t_shapes	**tab;
  int		i;
  int		k;
  
  i = -1;
  tab = NULL;
  get_tetrimino(&tab);
  while (tab && tab[++i])
    {
      k = -1;
      while (tab[i]->map[++k])
	printf("%s\n", tab[i]->map[k]);
    }
  while (tab && --i >= 0)
    {
      free_tab(&tab[i]->map);
      free(tab[i]);
    }
  free(tab);
}