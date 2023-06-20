/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floadfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:41:25 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/29 11:10:11 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_copy_floadfill(t_mlx *mlx)
{
	char	**new_tab;
	int		i;
	int		x;

	i = -1;
	new_tab = malloc(mlx->map.size_y * sizeof(char *));
	if (!new_tab)
		return (0);
	while (++i <= mlx->map.size_y)
	{
		x = -1;
		new_tab[i] = malloc(mlx->map.size_x * sizeof(char *));
		if (!new_tab[i])
			return (0);
		if (i == mlx->map.size_y - 1)
			return (new_tab);
		while (++x <= mlx->map.size_x)
			new_tab[i][x] = mlx->map.coords[i][x];
	}
	return (new_tab);
}

int	ft_check_element_map(t_mlx *mlx, char **tab, int y, int x)
{
	if (tab[y][x - 1] == '4')
	{
		mlx->map.get_items++;
		return (1);
	}
	else if (tab[y][x + 1] == '4')
	{
		mlx->map.get_items++;
		return (1);
	}
	else if (tab[y - 1][x] == '4')
	{
		mlx->map.get_items++;
		return (1);
	}
	else if (tab[y + 1][x] == '4')
	{
		mlx->map.get_items++;
		return (1);
	}
	return (0);
}

int	ft_check_floadfill(t_mlx *mlx, char **tab, int y, int x)
{
	(void) mlx;
	if (tab[y][x] == 'P')
		return (1);
	else if (tab[y][x] == 'C' || tab[y][x] == 'E')
		return (ft_check_element_map(mlx, tab, y, x));
	else if (tab[y][x - 1] == '4' && tab[y][x] == '0')
		return (1);
	else if (tab[y][x + 1] == '4' && tab[y][x] == '0')
		return (1);
	else if (tab[y - 1][x] == '4' && tab[y][x] == '0')
		return (1);
	else if (tab[y + 1][x] == '4' && tab[y][x] == '0')
		return (1);
	return (0);
}

void	ft_algo_check(t_mlx *mlx)
{
	int		x;
	int		y;
	char	**temp;

	temp = ft_copy_floadfill(mlx);
	x = 0;
	y = 0;
	while (++y < mlx->map.size_y - 1)
	{
		while (++x < mlx->map.size_x - 1)
		{
			if (ft_check_floadfill(mlx, temp, y, x) == 1)
			{
				temp[y][x] = '4';
				x = 1;
				y = 1;
			}
		}
		x = 0;
	}
	free(temp);
}

int	ft_is_winnable(t_mlx *mlx)
{
	int		tot;

	mlx->map.get_items = 0;
	tot = mlx->map.nb_items + 1;
	ft_algo_check(mlx);
	if (mlx->map.get_items == tot)
	{
		mlx->map.get_items = 0;
		return (1);
	}
	return (0);
}
