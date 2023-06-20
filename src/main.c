/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:49:58 by abourgue          #+#    #+#             */
/*   Updated: 2023/06/20 14:00:16 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_check_arg(int check, char *path, t_mlx *mlx)
{
	if (check != 2)
		ft_exit(mlx);
	mlx->map.path = path;
}

void	move_player(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	if (ft_move_check(mlx) == 1)
		ft_exit(mlx);
	ft_print_map(mlx);
	mlx->assets.img = mlx_xpm_file_to_image(mlx->mlx, mlx->assets.path,
			&mlx->assets.width, &mlx->assets.height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->assets.img,
		mlx->player.pos[0], mlx->player.pos[1]);
	free(mlx->assets.path);
	if (mlx->start == 1)
	{
		mlx->player.count++;
		ft_putstr("move: ");
		ft_putnbr(mlx->player.count);
		ft_putstr("\n");
	}
}

int	main(int argc, char **argv)
{
	static t_mlx	mlx;

	mlx.start = 0;
	mlx.mlx = mlx_init();
	ft_check_arg(argc, argv[1], &mlx);
	mlx.assets.path = ft_strjoin("", "./assets/basic_stand_S.xpm");
	if (ft_create_map(&mlx) != 1)
		return (ft_exit(&mlx));
	mlx.win = mlx_new_window(mlx.mlx, mlx.map.size_x * 50,
			mlx.map.size_y * 50, "so_long");
	if (ft_print_map(&mlx) != 1)
		return (ft_exit(&mlx));
	move_player(&mlx);
	mlx.start = 1;
	mlx_hook(mlx.win, 2, 1L << 0, keypress, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, ft_exit, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
