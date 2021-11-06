/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:26:07 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/06 13:54:59 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_map(char **map, t_pos *pos, t_input input)
{
	if (input.down)
		map[pos->y + 1][pos->x] = 'P';
	else if (input.up)
		map[pos->y - 1][pos->x] = 'P';
	else if (input.left)
		map[pos->y][pos->x - 1] = 'P';
	else if (input.right)
		map[pos->y][pos->x + 1] = 'P';
	else
		return (0);
	map[pos->y][pos->x] = '0';
	return (1);
}

t_pos	*get_player_pos(char **map)
{
	t_pos	*pos;
	int		x;
	int		y;

	pos = malloc(sizeof(t_pos));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos->x = x;
				pos->y = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

void	collisions(t_mlx *mlx, t_pos *pos, t_input input)
{
	if (exit_collision(mlx->plyr->map, pos, input))
	{
		if (mlx->plyr->coins <= 0)
		{
			mlx->plyr->map[pos->y][pos->x] = '0';
			mlx->plyr->step++;
			printf("Steps : %d || ", mlx->plyr->step);
			printf("Collected : %d || ", mlx->plyr->collected);
			printf("Coins Left : %d\n", mlx->plyr->coins);
			printf("Congrats!!!!!!!!!!\n");
			mlx->plyr->end = 1;
			return ;
		}
	}
	else
	{
		if (check_input(input))
		{
			mlx->plyr->step++;
			printf("Steps : %d || ", mlx->plyr->step);
			printf("Collected : %d || ", mlx->plyr->collected);
			printf("Coins Left : %d\n", mlx->plyr->coins);
		}
		if (col_collision(mlx->plyr->map, pos, input))
		{
			printf("You Got a Coin\n");
			mlx->plyr->collected++;
			mlx->plyr->coins--;
		}
		update_map(mlx->plyr->map, pos, input);
	}
}

void	move_player(t_mlx *mlx)
{
	t_pos	*pos;
	t_input	input;

	input = mlx->plyr->input;
	pos = get_player_pos(mlx->plyr->map);
	if (pos && !wall_collision(mlx->plyr->map, pos, input))
	{
		collisions(mlx, pos, input);
	}
	if (pos)
		free(pos);
	refresh_input(&mlx->plyr->input);
}

void	game(t_mlx *mlx)
{
	if (mlx->plyr->end == 1)
		return ;
	if (mlx->plyr->coins == 0 && mlx->plyr->col_bool == 0)
	{
		mlx->plyr->col_bool = 1;
		printf("Door Unlocked\n");
	}
	
	move_player((t_mlx *)mlx);
}
