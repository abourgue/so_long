/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:02:41 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/29 11:17:12 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	keypress(int keycode, t_mlx *vars)
{
	if (keycode == 53)
		ft_exit(vars);
	else if (keycode == 13)
		w_key(vars);
	else if (keycode == 0)
		a_key(vars);
	else if (keycode == 1)
		s_key(vars);
	else if (keycode == 2)
		d_key(vars);
	return (0);
}

int	ft_check_x(t_mlx *mlx, char c)
{
	if (c == 'a')
	{
		if (mlx->map.coords[mlx->player.pos[1] / 50]
			[mlx->player.pos[0] / 50 - 1] != '1')
			return (1);
	}
	if (c == 'd')
	{
		if (mlx->map.coords[mlx->player.pos[1] / 50]
			[mlx->player.pos[0] / 50 + 1] != '1')
			return (1);
	}
	return (0);
}

int	ft_check_y(t_mlx *mlx, char c)
{
	if (c == 'w')
	{
		if (mlx->map.coords[mlx->player.pos[1] / 50 - 1]
			[mlx->player.pos[0] / 50] != '1')
			return (1);
	}
	if (c == 's')
	{
		if (mlx->map.coords[mlx->player.pos[1] / 50 + 1]
			[mlx->player.pos[0] / 50] != '1')
			return (1);
	}
	return (0);
}

int	ft_check_wall(t_mlx *mlx, char c)
{
	if (c == 'a')
	{
		if (ft_check_x(mlx, c) != 1)
			return (0);
	}
	else if (c == 'd')
	{
		if (ft_check_x(mlx, c) != 1)
			return (0);
	}
	else if (c == 'w')
	{
		if (ft_check_y(mlx, c) != 1)
			return (0);
	}
	else if (c == 's')
	{
		if (ft_check_y(mlx, c) != 1)
			return (0);
	}
	return (1);
}
