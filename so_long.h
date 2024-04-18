/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:35 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/18 18:09:13 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILESIZE 16
# define SCALE 4

# include "libft/libft.h"
# include "MLX42/MLX42.h"

typedef struct s_map
{
	int		length;
	int		height;
	char	**grid;
}	t_map;

typedef struct s_player
{
	int			x;
	int			y;
	mlx_image_t	*skin;
	int			moves;
}	t_player;

typedef struct s_textures
{
	mlx_texture_t	*path;
	mlx_texture_t	*wall;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit_c;
	mlx_texture_t	*exit_o;
	mlx_texture_t	*player;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	t_textures	textures;
	mlx_image_t	*path;
	mlx_image_t	*wall;
	mlx_image_t	*exit_c;
	mlx_image_t	*exit_o;
	mlx_image_t	*collect;
	t_map		map;
	t_player	player;
	int			collect_count;
}	t_game;

int		init_map(t_game *game, char *argv[]);
void	load_map(t_game *game, char **argv);
void	load_textures(t_game *game);
int		build_map(t_game *game);
void	build_tile(t_game *game, char c, int x, int y);

void	init_imgs(t_game *game);
void	create_img(t_game *game, char *p, mlx_texture_t **t, mlx_image_t **img);

void	check_map(t_game *game);
int		is_rectangle(t_game *game);
int		is_surrounded_by_walls(t_game *game);
int		is_playable(t_game *game);

void	key_hook(mlx_key_data_t keydata, void *param);
// void	update(void *param);

void	move_player(t_game *game, int x, int y);
int		is_wall(t_game *game, int x, int y);
void	collect(t_game *game, int x, int y);
int		find_instance(t_game *game, int x, int y);
void	is_exit(t_game *game);

void	free_map(char **map);
void	ft_error(void);
void 	ft_mlx_error(void);
#endif