/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:20:24 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/06 15:07:50 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	refresh(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, g_width, g_height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->ll, &mlx->end);
	return (0);
}

int	mouse_test(int key, int x, int y)
{
	g_y = y;
	g_x = x;
	key = 0;
	return 0;
}
int	render(t_mlx *mlx)
{
	draw_map(mlx, mlx->plyr->map);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	draw_others(mlx, mlx->plyr->map);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	char *collected = malloc(sizeof(char) * 100);
	char *steps = malloc(sizeof(char) * 100);
	char *remains = malloc(sizeof(char) * 100);
	
	char *x_posstr = malloc(sizeof(char) * 100);
	char *y_posstr = malloc(sizeof(char) * 100);
	mlx_mouse_hook(mlx->mlx_win, mouse_test, NULL);
	int x = g_x;
	int y = g_y;
	sprintf(x_posstr, "%d", x);
	sprintf(y_posstr, "%d", y);

	x_posstr = ft_strjoin(ft_strdup("x pos : "), x_posstr);
	y_posstr = ft_strjoin(ft_strdup("y pos : "), y_posstr);
	mlx_string_put(mlx->mlx, mlx->mlx_win, (g_width / 2) + (g_width / 4), 20, 0x00000000 , x_posstr);
	mlx_string_put(mlx->mlx, mlx->mlx_win, (g_width / 2) + (g_width / 4), 60, 0x00000000 , y_posstr);
	
	sprintf(collected, "%d", mlx->plyr->collected);
	collected = ft_strjoin(ft_strdup("collected : "), collected);
	sprintf(steps, "%d", mlx->plyr->step);
	steps = ft_strjoin(ft_strdup("steps : "), steps);
	sprintf(remains, "%d", mlx->plyr->coins);
	remains = ft_strjoin(ft_strdup("coins remaining : "), remains);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 10, 20, 0x00000000 , steps);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 10, 60, 0x00000000 , collected);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 10, 100, 0x00000000 , remains);
	if (mlx->plyr->coins == 0 && mlx->plyr->end == 0)
		mlx_string_put(mlx->mlx, mlx->mlx_win, g_width / 2, 20, 0x00000000 , "Door Unlocked");
	if (mlx->plyr->end == 1)
		mlx_string_put(mlx->mlx, mlx->mlx_win, g_width / 2, g_height / 2, 0x00FFFFFF , "Congrats !!!!!");

	uint64_t time = get_time();
	time = time - starttime;
	char *timestr = malloc(sizeof(char) * 100);
	sprintf(timestr, "%d", (int)time / 100);

	mlx_string_put(mlx->mlx, mlx->mlx_win, g_width / 2, 60, 0x00000000 , timestr);
	
	sprintf(steps, "%d", mlx->plyr->step);
	
	free(collected);
	free(remains);
	free(steps);
	return (0);
}

void loadnext(t_mlx *mlx)
{
	char	**map;
	static int index = 1;

	if (mlx->plyr->end == 1)
	{
		if (mlx->av[index + 1] != NULL)
			index ++;
		else
			index = 1;
		
		map = get_map(mlx->av + index);
		
		//resolution(map);
		//mlx = init_canvas();
		get_texture(mlx);
		check_tex_err(mlx, 1);
		init_player(mlx, map);
		starttime = get_time();
	}
	else
		return ; 
}

int	update(void *mlx)
{
	refresh((t_mlx *)mlx);
	get_input((t_mlx *)mlx);
	game((t_mlx *)mlx);
	render((t_mlx *)mlx);
	loadnext(mlx);
	return (0);
}
