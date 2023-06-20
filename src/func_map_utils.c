/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:12:18 by abourgue          #+#    #+#             */
/*   Updated: 2023/03/29 11:08:11 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_copy_line(t_mlx *mlx, char *line, int index)
{
	int	i;

	i = 0;
	if (line == NULL)
		return ;
	while (i < mlx->map.size_x && line[i] != '\n' && line[i] != '\0')
	{
		mlx->map.coords[index][i] = line[i];
		i++;
	}
	mlx->map.coords[index][i] = '\0';
	return ;
}

char	**ft_copy_ptr(t_mlx *mlx)
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
		new_tab[i] = malloc(mlx->map.size_x + 1 * sizeof(char *));
		if (!new_tab[i])
			return (0);
		if (i == mlx->map.size_y - 1)
		{
			free(mlx->map.coords);
			return (new_tab);
		}
		while (++x <= mlx->map.size_x && mlx->map.coords[i][x] != '\0')
			new_tab[i][x] = mlx->map.coords[i][x];
	}
	free(mlx->map.coords);
	return (new_tab);
}

int	ft_check_map(t_mlx *mlx)
{
	if (ft_first_last(mlx) != 1)
		return (0);
	if (ft_check_middle(mlx) != 1)
		return (0);
	if (ft_check_start(mlx) != 1)
		return (0);
	if (ft_check_end(mlx) != 1)
		return (0);
	if (ft_check_item(mlx) != 1)
		return (0);
	return (1);
}
