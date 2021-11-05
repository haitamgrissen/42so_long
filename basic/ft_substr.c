/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:03:09 by hgrissen          #+#    #+#             */
/*   Updated: 2021/11/04 20:07:17 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (0);
	while (s[i] != '\0' && len > 0)
	{
		string[i++] = s[start++];
		len--;
	}
	string[i] = '\0';
	return (string);
}
