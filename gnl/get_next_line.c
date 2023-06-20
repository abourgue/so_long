/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:55:02 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/23 11:46:57 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_gnl_init(int fd, t_gnl *gnl)
{
	gnl->pos = 0;
	gnl->fd = fd;
	gnl->maxb = read(gnl->fd, gnl->backup, BUFFER_SIZE);
	if (gnl->maxb <= 0)
		return (0);
	return (1);
}

char	ft_check_read(t_gnl *gnl)
{
	char	c;

	if (gnl->pos >= gnl->maxb)
	{
		gnl->pos = 0;
		gnl->maxb = read(gnl->fd, gnl->backup, BUFFER_SIZE);
		if (gnl->maxb <= 0)
			return (0);
	}
	c = gnl->backup[gnl->pos];
	gnl->pos++;
	return (c);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl = {.fd = -1};
	char			*res;
	char			c;

	res = NULL;
	if (gnl.fd != fd)
	{
		if (!ft_gnl_init(fd, &gnl))
			return (NULL);
	}
	c = ft_check_read(&gnl);
	while (c)
	{
		res = ft_join(res, c);
		if (c == '\n')
			return (res);
		c = ft_check_read(&gnl);
	}
	return (res);
}
