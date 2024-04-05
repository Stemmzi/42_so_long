/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:35 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/05 16:44:16 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILESIZE 16
# define SCALE 4

# include "libft/libft.h"
# include "MLX42/MLX42.h"

typedef struct s_game
{
	void			*mlx;
	void			*win;
	mlx_image_t*	img;
	int				x;
	int				y;
	char			**map;
}	t_game;

int		create_map(t_game *game, char *argv[]);
void	build_line(t_game *game, char *line);

void	build_space(void *mlx, int x, int y);
void	build_wall(void *mlx, int x, int y);
void	build_player(t_game *game, void *mlx, int x, int y);

void	key_hook(mlx_key_data_t keydata, void *param);

#endif