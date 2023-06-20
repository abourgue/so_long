/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:15:48 by abourgue          #+#    #+#             */
/*   Updated: 2023/04/05 11:44:52 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error_map(t_mlx *mlx, char *line)
{
	ft_putstr("Error\n");
	free(line);
	free(mlx->map.coords);
	return (ft_exit(mlx));
}

void	put_to_coords(t_mlx *mlx, char *line)
{
	if (mlx->map.size_y <= 1)
	{
		mlx->map.coords = malloc(mlx->map.size_y * sizeof(char *));
		mlx->map.coords[0] = malloc(mlx->map.size_x * sizeof(char *));
		ft_copy_line(mlx, line, 0);
		free(line);
		return ;
	}
	mlx->map.coords = ft_copy_ptr(mlx);
	ft_copy_line(mlx, line, mlx->map.size_y - 1);
	free(line);
	return ;
}

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == 'E' || line[i] == '0'
			|| line[i] == 'C' || line[i] == 'P' || line[i] == '\n'
			|| line[i] == 'V')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_map_init(t_mlx *mlx)
{
	int		i;
	char	*line;

	i = 1;
	mlx->map.coords = NULL;
	mlx->map.size_y = 1;
	mlx->map.fd = open(mlx->map.path, O_RDONLY);
	line = get_next_line(mlx->map.fd);
	if (line != NULL)
		mlx->map.size_x = ft_strlen(line) - 1;
	while (i == 1)
	{
		if (line == NULL && mlx->map.size_y <= 2)
			return (ft_error_map(mlx, line));
		if (line == NULL && mlx->map.size_y > 2)
			return (1);
		if (ft_check_line(line) != 1)
			return (ft_error_map(mlx, line));
		put_to_coords(mlx, line);
		line = get_next_line(mlx->map.fd);
		mlx->map.size_y++;
	}
	close(mlx->map.fd);
	return (1);
}

int	ft_create_map(t_mlx *mlx)
{
	if (ft_map_init(mlx) != 1)
		return (0);
	mlx->map.size_y--;
	if (ft_check_map(mlx) != 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ft_is_winnable(mlx) != 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}
