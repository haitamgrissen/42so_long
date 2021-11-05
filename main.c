/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:23:28 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/05 15:18:22 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_others(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1')
				rect(mlx, j * TILESIZE, i * TILESIZE, mlx->tex.w);
			if (map[i][j] == 'P')
				rect(mlx, j * TILESIZE, i * TILESIZE, mlx->tex.p);
			else if (map[i][j] == 'C')
				rect(mlx, j * TILESIZE, i * TILESIZE, mlx->tex.c);
			else if (map[i][j] == 'E')
				rect(mlx, j * TILESIZE, i * TILESIZE, mlx->tex.e);
			j++;
		}
		i++;
	}
}

void	draw_map(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				rect(mlx, j * TILESIZE, i * TILESIZE, mlx->tex.s);
			else if (map[i][j] != '1')
				rect(mlx, j * TILESIZE, i * TILESIZE, mlx->tex.w);
			j++;
		}
		i++;
	}
}

void	check_tex_err(t_mlx *mlx, int code)
{
	if (code == 0)
	{
		if (!mlx->tex.s.img || !mlx->tex.w.img
			|| !mlx->tex.e.img || !mlx->tex.c.img || !mlx->tex.p.img)
			exit_error(3);
	}
	else if (code == 1)
	{
		if (!mlx->tex.s.addr || !mlx->tex.w.addr
			|| !mlx->tex.e.addr ||!mlx->tex.c.addr || !mlx->tex.p.addr)
			exit_error(3);
	}
}

void	get_texture(t_mlx *mlx)
{
	int	w;
	int	h;

	mlx->tex.c.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/col.xpm", &w, &h);
	mlx->tex.e.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/exit.xpm", &w, &h);
	mlx->tex.p.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/player.xpm", &w, &h);
	mlx->tex.w.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/grass1.xpm", &w, &h);
	mlx->tex.s.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/grass2.xpm", &w, &h);
	check_tex_err(mlx, 0);
	mlx->tex.c.addr = (unsigned int *)mlx_get_data_addr(mlx->tex.c.img,
			&mlx->tex.c.bpp, &mlx->tex.c.ll, &mlx->tex.c.end);
	mlx->tex.e.addr = (unsigned int *)mlx_get_data_addr(mlx->tex.e.img,
			&mlx->tex.e.bpp, &mlx->tex.e.ll, &mlx->tex.e.end);
	mlx->tex.p.addr = (unsigned int *)mlx_get_data_addr(mlx->tex.p.img,
			&mlx->tex.p.bpp, &mlx->tex.p.ll, &mlx->tex.p.end);
	mlx->tex.w.addr = (unsigned int *)mlx_get_data_addr(mlx->tex.w.img,
			&mlx->tex.w.bpp, &mlx->tex.w.ll, &mlx->tex.w.end);
	mlx->tex.s.addr = (unsigned int *)mlx_get_data_addr(mlx->tex.s.img,
			&mlx->tex.s.bpp, &mlx->tex.s.ll, &mlx->tex.s.end);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;
	char	**map;

	if (ac != 2)
		return (exit_error(0));
	map = get_map(av);
	resolution(map);
	mlx = init_canvas();
	get_texture(mlx);
	check_tex_err(mlx, 1);
	init_player(mlx, map);
	mlx_loop_hook(mlx->mlx, update, mlx);
	mlx_loop(mlx);
}
