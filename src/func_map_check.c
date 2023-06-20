/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:01:50 by abourgue          #+#    #+#             */
/*   Updated: 2023/06/20 14:01:04 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_first_last(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.size_x)
	{
		if (mlx->map.coords[0][i] != '1')
			return (0);
		if (mlx->map.coords[mlx->map.size_y - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_middle(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.size_y)
	{
		if (mlx->map.coords[i][0] != '1'
			|| mlx->map.coords[i][mlx->map.size_x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_start(t_mlx *mlx)
{
	int	i;
	int	x;
	int	z;

	i = 0;
	z = 0;
	while (++i < mlx->map.size_y - 1)
	{
		x = -1;
		while (++x < mlx->map.size_x)
		{
			if (mlx->map.coords[i][x] == 'P')
			{
				mlx->player.pos[0] = x * 50;
				mlx->player.pos[1] = i * 50;
				z++;
			}
		}
	}
	if (z == 1)
		return (1);
	return (0);
}

int	ft_check_end(t_mlx *mlx)
{
	int	i;
	int	x;
	int	z;

	i = 0;
	z = 0;
	while (++i < mlx->map.size_y - 1)
	{
		x = -1;
		while (++x < mlx->map.size_x)
		{
			if (mlx->map.coords[i][x] == 'E')
			{
				mlx->map.pos_end[0] = i;
				mlx->map.pos_end[1] = x;
				z++;
			}
		}
	}
	if (z == 1)
		return (1);
	return (0);
}

int	ft_check_item(t_mlx *mlx)
{
	int	i;
	int	x;

	i = 0;
	mlx->map.nb_items = 0;
	while (++i < mlx->map.size_y - 1)
	{
		x = -1;
		while (++x < mlx->map.size_x)
		{
			if (mlx->map.coords[i][x] == 'C')
				mlx->map.nb_items++;
		}
	}
	mlx->map.get_items = 0;
	if (mlx->map.nb_items >= 1)
		return (1);
	return (0);
}
