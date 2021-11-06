/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:37:39 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/06 10:50:07 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_coins(char **map)
{
	int	coins;
	int	i;
	int	j;

	coins = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}

void	init_player(t_mlx *mlx, char **map)
{
	mlx->plyr = malloc(sizeof(t_player));
	mlx->plyr->map = map;
	mlx->plyr->step = 0;
	mlx->plyr->end = 0;
	mlx->plyr->collected = 0;
	mlx->plyr->col_bool = 0;
	mlx->plyr->coins = get_coins(mlx->plyr->map);
}

t_mlx	*init_canvas(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, g_width, g_height, "SO LONG");
	mlx->img = mlx_new_image(mlx->mlx, g_width, g_height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->ll, &mlx->end);
	return (mlx);
}

void	resolution(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	g_height = i * TILESIZE;
	g_width = ft_strlen(map[2]) * TILESIZE;
}
