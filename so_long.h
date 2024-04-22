/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:17:35 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/22 17:51:54 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILESIZE 16
# define SCALE 4

# include "libft/libft.h"
# include "MLX42/MLX42.h"

# include "errno.h"

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
	char		*my_error;
}	t_game;

void	init_map(t_game *game, char *argv[]);
void	load_map(t_game *game, char **argv);
void	build_map(t_game *game);

void	load_textures(t_game *game);
void	init_imgs(t_game *game);
void	create_img(t_game *game, char *p, mlx_texture_t **t, mlx_image_t **img);
void	ft_mlx_image_to_window(t_game *game, mlx_image_t *img, int x, int y);

void	check_map(t_game *game);
int		is_rectangle(t_game *game);
int		is_surrounded_by_walls(t_game *game);
int		is_playable(t_game *game);

void	key_hook(mlx_key_data_t keydata, void *param);

void	move_player(t_game *game, int x, int y);
int		is_wall(t_game *game, int x, int y);
void	collect(t_game *game, int x, int y);
void	is_exit(t_game *game);

void	clean_exit(t_game *game);
void	free_map(char **map);
void	free_textures(t_textures tex);
void	ft_mlx_error(void);
void	ft_error(void);
#endif