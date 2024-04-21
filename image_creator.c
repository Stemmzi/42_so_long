/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:40:55 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/21 21:35:34 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_game *game)
{
	create_img(game, "./textures/path.png", &game->textures.path,
		&game->path);
	create_img(game, "./textures/wall.png", &game->textures.wall,
		&game->wall);
	create_img(game, "./textures/collectible.png", &game->textures.collect,
		&game->collect);
	create_img(game, "./textures/exit_closed.png", &game->textures.exit_c,
		&game->exit_c);
	create_img(game, "./textures/exit_open.png", &game->textures.exit_o,
		&game->exit_o);
	create_img(game, "./textures/player.png", &game->textures.player,
		&game->player.skin);
}

void	create_img(t_game *game, char *p, mlx_texture_t **t, mlx_image_t **img)
{
	int	size;

	size = TILESIZE * SCALE;
	*t = mlx_load_png(p);
	if (!t)
		clean_exit(game);
	*img = mlx_texture_to_image(game->mlx, *t);
	if (!mlx_resize_image(*img, size, size))
		clean_exit(game);
}

void	ft_mlx_image_to_window(t_game *game, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(game->mlx, img, x, y) < 0)
		clean_exit(game);
}
