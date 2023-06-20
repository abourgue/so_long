/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:42:54 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/30 14:05:44 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_exit(t_mlx *mlx)
{
	(void) mlx;
	exit(0);
	return (0);
}

void	w_key(t_mlx *mlx)
{
	if (mlx->player.pos[1] <= 0)
		return ;
	if (ft_check_wall(mlx, 'w') == 1)
	{
		mlx->assets.path = ft_strjoin("", "./assets/basic_stand_W.xpm");
		mlx->player.pos[1] -= 50;
		move_player(mlx);
	}
	else
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_print_map(mlx);
		mlx->assets.path = ft_strjoin("", "./assets/basic_stand_W.xpm");
		mlx->assets.img = mlx_xpm_file_to_image(mlx->mlx, mlx->assets.path,
				&mlx->assets.width, &mlx->assets.height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.img,
			mlx->player.pos[0], mlx->player.pos[1]);
		free(mlx->assets.path);
	}
}

void	a_key(t_mlx *mlx)
{
	if (mlx->player.pos[0] <= 0)
		return ;
	if (ft_check_wall(mlx, 'a') == 1)
	{
		mlx->assets.path = ft_strjoin("", "./assets/basic_stand_A.xpm");
		mlx->player.pos[0] -= 50;
		move_player(mlx);
	}
	else
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_print_map(mlx);
		mlx->assets.path = ft_strjoin("", "./assets/basic_stand_A.xpm");
		mlx->assets.img = mlx_xpm_file_to_image(mlx->mlx, mlx->assets.path,
				&mlx->assets.width, &mlx->assets.height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.img,
			mlx->player.pos[0], mlx->player.pos[1]);
		free(mlx->assets.path);
	}
}

void	s_key(t_mlx *mlx)
{
	if (mlx->player.pos[1] >= (mlx->map.size_y * 50) - 50)
		return ;
	if (ft_check_wall(mlx, 's') == 1)
	{
		mlx->assets.path = ft_strjoin("", "./assets/basic_stand_S.xpm");
		mlx->player.pos[1] += 50;
		move_player(mlx);
	}
	else
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_print_map(mlx);
		mlx->assets.path = ft_strjoin("", "./assets/basic_stand_S.xpm");
		mlx->assets.img = mlx_xpm_file_to_image(mlx->mlx, mlx->assets.path,
				&mlx->assets.width, &mlx->assets.height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.img,
			mlx->player.pos[0], mlx->player.pos[1]);
		free(mlx->assets.path);
	}
}

void	d_key(t_mlx *mlx)
{
	if (mlx->player.pos[0] >= (mlx->map.size_x * 50) - 50)
		return ;
	if (ft_check_wall(mlx, 'd') == 1)
	{
		mlx->assets.path = ft_strjoin("", "./assets/basic_stand_D.xpm");
		mlx->player.pos[0] += 50;
		move_player(mlx);
	}
	else
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		ft_print_map(mlx);
		mlx->assets.path = ft_strjoin("", "./assets/basic_stand_D.xpm");
		mlx->assets.img = mlx_xpm_file_to_image(mlx->mlx, mlx->assets.path,
				&mlx->assets.width, &mlx->assets.height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.img,
			mlx->player.pos[0], mlx->player.pos[1]);
		free(mlx->assets.path);
	}
}
