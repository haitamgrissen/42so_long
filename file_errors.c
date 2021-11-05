/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:30:26 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/05 16:02:07 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_file(char **av)
{
	int		fd;
	char	*line;
	char	*str;

	fd = open(av[1], O_RDONLY);
	str = ft_strdup("");
	if (fd < 0)
		exit_error(1);
	while (get_next_line(fd, &line))
	{
		str = ft_strjoin(str, line);
		str = ft_strjoin(str, ft_strdup("\n"));
	}
	str = ft_strjoin(str, line);
	return (str);
}

void	check_elements_count(char *str)
{
	int			i;
	t_elements	el;

	i = -1;
	el.c = 0;
	el.p = 0;
	el.e = 0;
	while (str[++i])
	{
		if (str[i] == 'C')
			el.c++;
		if (str[i] == 'E')
			el.e++;
		if (str[i] == 'P')
			el.p++;
	}
	if (el.c < 1 || el.e < 1 || el.p != 1)
		exit_error(2);
}

void	check_map_chars(char *str)
{
	int	i;
	int	fnnwl;

	i = -1;
	fnnwl = 0;
	while (str[++i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'P' && str[i] != '\n')
			exit_error(2);
		if (str[i] == '\n')
		{
			if (fnnwl == 1)
				exit_error(2);
			fnnwl = 1;
		}
		else
			fnnwl = 0;
	}
}

void	check_map_closed(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != '1')
				exit_error(2);
			if (map[i + 1] == NULL && map[i][j] != '1')
				exit_error(2);
			if (j == 0 && map[i][j] != '1')
				exit_error(2);
			if (j == len - 1 && map[i][j] != '1')
				exit_error(2);
			j++;
		}
		if (!map[i][j] && j != len)
			exit_error(2);
		i++;
	}
}
