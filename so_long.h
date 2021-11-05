/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:17:07 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/05 15:23:26 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <signal.h>
# include "./basic/libft.h"
# include "./gnl/get_next_line.h"

# define FLT_MAX 3.402823e+38

# define W 1080
# define H 720 

# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define W_KEY 13
# define ESC_KEY 53
# define L_ARR 123
# define R_ARR 124
# define U_ARR 126
# define D_ARR 125
# define SPACE 49
# define TAB 48

# define TILESIZE 64

typedef struct s_elements
{
	int	p;
	int	c;
	int	e;
}		t_elements;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_input
{
	int	pressed;
	int	up;
	int	down;
	int	left;
	int	right;
}		t_input;

typedef struct s_img {
	void				*img;
	unsigned int		*addr;
	int					bpp;
	int					ll;
	int					end;
}						t_img;

int	g_width;
int	g_height;

typedef struct s_textures
{
	t_img	p;
	t_img	e;
	t_img	c;
	t_img	w;
	t_img	s;
}			t_textures;

typedef struct s_player
{
	t_input	input;
	int		step;
	int		coins;
	int		end;
	char	**map;
}			t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			end;
	t_player	*plyr;
	t_textures	tex;
}				t_mlx;

int		update(void *mlx);
int		ft_quit(void);

int		exit_error(int error);

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void	rect(t_mlx *mlx, int x, int y, t_img tex);
void	draw_map(t_mlx *mlx, char **map);

void	move_player(t_mlx *mlx);
int		get_coins(char **map);

/*
	collisions
*/
int		exit_collision(char **map, t_pos *pos, t_input input);
int		wall_collision(char **map, t_pos *pos, t_input input);
int		col_collision(char **map, t_pos *pos, t_input input);

/*
	inputs
*/
void	refresh_input(t_input *input);
void	get_input(t_mlx *mlx);
int		key_pressed(int key, t_mlx *mlx);
int		key_released(int key, t_mlx *mlx);

char	**get_map(char	**av);

void	check_map_closed(char **map);
void	check_map_chars(char *str);
void	check_elements_count(char *str);
char	*get_file(char **av);

void	init_player(t_mlx *mlx, char **map);
t_mlx	*init_canvas(void);

void	draw_others(t_mlx *mlx, char **map);

void	game(t_mlx *mlx);

int		check_input(t_input input);
void	resolution(char **map);

#endif
