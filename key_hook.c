/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:40:08 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/05 16:48:10 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->img->instances[0].x += 0;
		game->img->instances[0].y += -64;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->img->instances[0].x += -64;
		game->img->instances[0].y += 0;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->img->instances[0].x += 0;
		game->img->instances[0].y += 64;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->img->instances[0].x += 64;
		game->img->instances[0].y += 0;
	}
}
