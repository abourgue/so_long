/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_move_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:25:02 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/28 14:34:54 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_collect_item(t_mlx *mlx)
{
	if (mlx->map.coords[mlx->player.pos[1] / 50]
		[mlx->player.pos[0] / 50] == 'C')
	{
		mlx->map.get_items++;
		mlx->map.coords[mlx->player.pos[1] / 50]
		[mlx->player.pos[0] / 50] = '0';
		return (1);
	}
	return (0);
}

int	ft_move_check(t_mlx *mlx)
{
	if (ft_check_collect_item(mlx) == 1)
		return (0);
	if (mlx->map.coords[mlx->player.pos[1] / 50]
		[mlx->player.pos[0] / 50] == 'E'
		&& mlx->map.get_items == mlx->map.nb_items)
	{
		mlx->assets.img = mlx_xpm_file_to_image(mlx->mlx, mlx->assets.path,
				&mlx->assets.width, &mlx->assets.height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.img,
			mlx->player.pos[0], mlx->player.pos[1]);
		mlx->player.count++;
		return (1);
	}
	return (0);
}
