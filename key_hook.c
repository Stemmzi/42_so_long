/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:40:08 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/23 22:56:43 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		game->my_error = "Game closed\n";
		clean_exit(game);
	}
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(game, 0, -1);
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(game, -1, 0);
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(game, 0, 1);
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		move_player(game, 1, 0);
}

void	move_player(t_game *game, int x, int y)
{
	int	size;

	size = TILESIZE * SCALE;
	if (!is_wall(game, game->player.x + x, game->player.y + y))
	{
		game->player.skin->instances[0].y += y * size;
		game->player.y += y;
		game->player.skin->instances[0].x += x * size;
		game->player.x += x;
		game->player.moves += 1;
		ft_printf("%d\n", game->player.moves);
		if (game->player.moves_to_exit != 0 && game->player.moves > 0)
		{
			game->player.moves_to_exit--;
			if (game->player.moves_to_exit == 0)
				game->player.moves_to_exit = -1;
		}
	}
	if (game->map.grid[game->player.y][game->player.x] == 'C')
		collect(game, game->player.x, game->player.y);
	if (game->map.grid[game->player.y][game->player.x] == 'E')
		is_exit(game);
}
