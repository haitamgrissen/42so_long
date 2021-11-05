/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:56:18 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/04 20:09:39 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_collision(char **map, t_pos *pos, t_input input)
{
	if (input.down && map[pos->y + 1][pos->x] == 'E')
		return (1);
	else if (input.up && map[pos->y - 1][pos->x] == 'E')
		return (1);
	else if (input.left && map[pos->y][pos->x - 1] == 'E')
		return (1);
	else if (input.right && map[pos->y][pos->x + 1] == 'E')
		return (1);
	return (0);
}

int	col_collision(char **map, t_pos *pos, t_input input)
{
	if (input.down && map[pos->y + 1][pos->x] == 'C')
		return (1);
	else if (input.up && map[pos->y - 1][pos->x] == 'C')
		return (1);
	else if (input.left && map[pos->y][pos->x - 1] == 'C')
		return (1);
	else if (input.right && map[pos->y][pos->x + 1] == 'C')
		return (1);
	return (0);
}

int	wall_collision(char **map, t_pos *pos, t_input input)
{
	if (input.down && map[pos->y + 1][pos->x] == '1')
		return (1);
	else if (input.up && map[pos->y - 1][pos->x] == '1')
		return (1);
	else if (input.left && map[pos->y][pos->x - 1] == '1')
		return (1);
	else if (input.right && map[pos->y][pos->x + 1] == '1')
		return (1);
	return (0);
}
