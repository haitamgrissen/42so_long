/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:20:24 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/05 15:23:26 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	refresh(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, g_width, g_height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->ll, &mlx->end);
	return (0);
}

int	render(t_mlx *mlx)
{
	draw_map(mlx, mlx->plyr->map);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	draw_others(mlx, mlx->plyr->map);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	return (0);
}

int	update(void *mlx)
{
	refresh((t_mlx *)mlx);
	get_input((t_mlx *)mlx);
	game((t_mlx *)mlx);
	render((t_mlx *)mlx);
	return (0);
}
