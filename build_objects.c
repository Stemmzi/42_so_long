/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:40:55 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/17 00:12:52 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	int				size;

	size = TILESIZE * SCALE;
	game->textures.path = mlx_load_png("./textures/path.png");
	game->textures.wall = mlx_load_png("./textures/wall.png");
	game->textures.collect = mlx_load_png("./textures/collectible.png");
	game->textures.exit_c = mlx_load_png("./textures/exit_closed.png");
	game->textures.exit_o = mlx_load_png("./textures/exit_open.png");
	game->textures.player = mlx_load_png("./textures/player.png");
	game->path = mlx_texture_to_image(game->mlx, game->textures.path);
	game->wall = mlx_texture_to_image(game->mlx, game->textures.wall);
	game->collect = mlx_texture_to_image(game->mlx, game->textures.collect);
	game->exit_c = mlx_texture_to_image(game->mlx, game->textures.exit_c);
	game->exit_o = mlx_texture_to_image(game->mlx, game->textures.exit_o);
	game->player.skin = mlx_texture_to_image(game->mlx, game->textures.player);
	mlx_resize_image(game->path, size, size);
	mlx_resize_image(game->wall, size, size);
	mlx_resize_image(game->collect, size, size);
	mlx_resize_image(game->exit_c, size, size);
	mlx_resize_image(game->exit_o, size, size);
	mlx_resize_image(game->player.skin, size, size);
}
