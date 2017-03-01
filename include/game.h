/*
** game.h for tetris in /home/thibrex/Dropbox/delivery/PSU/PSU_2016_tetris
** 
** Made by Thibaut Cornolti
** Login   <thibaut.cornolti@epitech.eu>
** 
** Started on  Tue Feb 28 17:08:20 2017 Thibaut Cornolti
** Last update Wed Mar  1 17:41:02 2017 Bastien
*/

#ifndef GAME_H_
# define GAME_H_

typedef struct	s_shapes t_shapes;

typedef struct	s_game
{
  int		high_score;
  int		score;
  int		line;
  int		level;
  int		timer;
  int		start_time;
}		t_game;

typedef struct	s_pos
{
  int		x;
  int		y;
  int		index;
  int		orient;
  char		**map;
  int		color;
}		t_pos;

void		init_game(t_game *, t_pars *);
int		get_action(t_pars *);
void		game(t_shapes *, t_pars *, t_game *);
void		apply_action(int, char **, t_pos *, t_shapes *);
void		falling_shapes(char **, t_pos *);

#endif /* !GAME_H_ */
