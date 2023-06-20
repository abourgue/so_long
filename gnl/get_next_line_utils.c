/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:05:32 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/23 11:37:07 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_join(char *s, char c)
{
	int		len_s;
	char	*res;
	int		i;

	len_s = ft_len(s);
	res = malloc(len_s + 2);
	i = 0;
	if (!res)
		return (NULL);
	while (i < len_s)
	{
		res[i] = s[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	if (s)
		free(s);
	return (res);
}
