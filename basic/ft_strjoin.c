/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:16:04 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/05 16:03:07 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	int			i;
	int			j;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}
