/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgue <abourgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:50:17 by abourgue          #+#    #+#             */
/*   Updated: 2023/04/05 11:47:33 by abourgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>

# include "get_next_line.h"
# include "libft.h"
# include "../mlx/mlx.h"

typedef struct s_map {
	char	**coords;
	int		*texture_type;
	char	*path;
	int		pos_end[2];
	int		nb_items;
	int		get_items;
	int		size_y;
	int		size_x;
	int		fd;
}				t_map;

typedef struct s_player {
	int	pos[2];
	int	count;
}				t_player;

typedef struct s_assets {
	void	*img;
	char	*path;
	int		width;
	int		height;

}				t_assets;

typedef struct s_mlx {
	void		*win;
	void		*mlx;
	char		*addr;
	int			start;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_player	player;
	t_assets	assets;
	t_map		map;
}				t_mlx;

void	move_player(t_mlx *mlx);
void	w_key(t_mlx *mlx);
void	a_key(t_mlx *mlx);
void	s_key(t_mlx *mlx);
void	d_key(t_mlx *mlx);
int		ft_exit(t_mlx *mlx);
int		keypress(int keycode, t_mlx *mlx);
int		ft_create_map(t_mlx *mlx);
int		ft_error_map(t_mlx *mlx, char *line);
char	**ft_copy_ptr(t_mlx *mlx);
void	ft_copy_line(t_mlx *mlx, char *line, int index);
int		ft_check_map(t_mlx *mlx);
int		ft_first_last(t_mlx *mlx);
int		ft_check_middle(t_mlx *mlx);
int		ft_check_start(t_mlx *mlx);
int		ft_check_end(t_mlx *mlx);
int		ft_check_item(t_mlx *mlx);
int		ft_print_map(t_mlx *mlx);
int		ft_check_wall(t_mlx *mlx, char c);
int		ft_move_check(t_mlx *mlx);
int		ft_is_winnable(t_mlx *mlx);
#endif