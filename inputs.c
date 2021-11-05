/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:26:27 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/05 13:41:54 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_mlx *mlx)
{
	int	p;

	p = mlx->plyr->input.pressed;
	if (key == ESC_KEY)
		ft_quit();
	else if (key == A_KEY && !p)
		mlx->plyr->input.left = 1;
	else if (key == D_KEY && !p)
		mlx->plyr->input.right = 1;
	else if (key == S_KEY && !p)
		mlx->plyr->input.down = 1;
	else if (key == W_KEY && !p)
		mlx->plyr->input.up = 1;
	else
		return (0);
	mlx->plyr->input.pressed = 1;
	return (1);
}

int	key_released(int key, t_mlx *mlx)
{
	if (key == A_KEY)
		mlx->plyr->input.left = 0;
	else if (key == D_KEY)
		mlx->plyr->input.right = 0;
	else if (key == S_KEY)
		mlx->plyr->input.down = 0;
	else if (key == W_KEY)
		mlx->plyr->input.up = 0;
	else
		return (0);
	mlx->plyr->input.pressed = 0;
	return (1);
}

int	check_input(t_input input)
{
	if (input.up || input.down || input.right || input.left)
		return (1);
	return (0);
}

void	refresh_input(t_input *input)
{
	input->up = 0;
	input->down = 0;
	input->left = 0;
	input->right = 0;
}

void	get_input(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_win, 2, 0, key_pressed, mlx);
	mlx_hook(mlx->mlx_win, 3, 0, key_released, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, ft_quit, mlx);
}
