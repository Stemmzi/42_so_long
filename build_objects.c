/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:40:55 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/02 22:09:32 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_space(void *mlx, int x, int y)
{
	mlx_texture_t *texture;
	mlx_image_t	*img;

	texture = mlx_load_png("./textures/path.png");
	img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, 64, 64);
	mlx_image_to_window(mlx, img, img->width * x, img->width * y);
}

void	build_wall(void *mlx, int x, int y)
{
	mlx_texture_t *texture;
	mlx_image_t	*img;

	texture = mlx_load_png("./textures/wall.png");
	img = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(img, 64, 64);
	mlx_image_to_window(mlx, img, img->width * x, img->width * y);
}

// void	build_collectible(char *line, int x)
// {
// }

// void	build_exit(char *line, int x)
// {
// }

void	build_player(t_game *game, void *mlx, int x, int y)
{
	mlx_texture_t *texture;

	texture = mlx_load_png("./textures/player.png");
	game->img  = mlx_texture_to_image(mlx, texture);
	mlx_resize_image(game->img , 64, 64);
	mlx_image_to_window(mlx, game->img , game->img->width * x, game->img->width * y);
	mlx_set_instance_depth(&game->img->instances[0], 63);
}