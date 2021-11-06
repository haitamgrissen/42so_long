/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:45:40 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/05 18:10:07 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if (x < g_width && x >= 0 && y < g_height && y >= 0)
	{
		dst = data->addr + (y * data->ll + x * (data->bpp / 8));
		*(unsigned int *) dst = color;
	}
}

void	rect(t_mlx *mlx, int x, int y, t_img tex)
{
	int	i;
	int	j;
	int	pos;

	i = y;
	while (i < y + TILESIZE)
	{
		j = x;
		while (j < x + TILESIZE)
		{
			pos = ((i - y) * TILESIZE + (j - x));
			my_mlx_pixel_put(mlx, j, i, tex.addr[pos]);
			j++;
		}
		i++;
	}
}
