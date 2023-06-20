/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_print_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:43:44 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/30 14:11:39 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_assets(t_mlx *mlx, int y, int x)
{
	mlx->assets.img = mlx_xpm_file_to_image(mlx->mlx, mlx->map.path,
			&mlx->assets.width, &mlx->assets.height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.img, x, y);
	free(mlx->map.path);
}

void	ft_print_spe(t_mlx *mlx, int y, int x)
{
	mlx->map.path = ft_strjoin("", "./assets/void_text.xpm");
	ft_print_assets(mlx, y, x);
}

void	ft_select_assets(t_mlx *mlx, int num_line, int c_pos)
{
	if (mlx->map.coords[num_line][c_pos] == '0')
		mlx->map.path = ft_strjoin("", "./assets/void_text.xpm");
	else if (mlx->map.coords[num_line][c_pos] == '1')
		mlx->map.path = ft_strjoin("", "./assets/wall_text.xpm");
	else if (mlx->map.coords[num_line][c_pos] == 'P')
	{
		ft_print_spe(mlx, num_line * 50, c_pos * 50);
		mlx->map.coords[num_line][c_pos] = '0';
		mlx->map.path = ft_strjoin("", "./assets/basic_stand_S.xpm");
	}
	else if (mlx->map.coords[num_line][c_pos] == 'E')
	{
		ft_print_spe(mlx, num_line * 50, c_pos * 50);
		mlx->map.path = ft_strjoin("", "./assets/exit_text.xpm");
	}
	else if (mlx->map.coords[num_line][c_pos] == 'C')
	{
		ft_print_spe(mlx, num_line * 50, c_pos * 50);
		mlx->map.path = ft_strjoin("", "./assets/collect_text.xpm");
	}
	else if (mlx->map.coords[num_line][c_pos] == 'V')
	{
		ft_print_spe(mlx, num_line * 50, c_pos * 50);
		mlx->map.path = ft_strjoin("", "./assets/enemy.xpm");
	}
}

int	ft_print_map(t_mlx *mlx)
{
	int	i;
	int	x;

	i = 0;
	while (i < mlx->map.size_y)
	{
		x = 0;
		while (x < mlx->map.size_x)
		{
			ft_select_assets(mlx, i, x);
			ft_print_assets(mlx, i * 50, x * 50);
			x++;
		}
		i++;
	}
	return (1);
}
