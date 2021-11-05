/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:22:25 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/05 15:46:53 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char	**av)
{
	char	*str;
	char	**map;

	str = get_file(av);
	check_map_chars(str);
	check_elements_count(str);
	map = ft_split(str, '\n');
	free(str);
	check_map_closed(map);
	return (map);
}
