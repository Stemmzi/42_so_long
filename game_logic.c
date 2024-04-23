/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:22:33 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/23 22:49:08 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == '1')
		return (1);
	return (0);
}

static int	find_instance(t_game *game, int x, int y)
{
	int	count;
	int	size;

	count = 0;
	size = TILESIZE * SCALE;
	while (game->collect->instances[count].x != x * size
		|| game->collect->instances[count].y != y * size)
		count++;
	return (count);
}

void	collect(t_game *game, int x, int y)
{
	int	count;

	count = find_instance(game, x, y);
	if (game->collect->instances[count].enabled == true)
	{
		game->collect->instances[count].enabled = false;
		game->collect_count--;
	}
	if (game->collect_count == 0 && game->exit_o->count < 1)
	{
		game->exit_c->instances[0].enabled = false;
		ft_mlx_image_to_window(game, game->exit_o,
			game->exit_c->instances[0].x, game->exit_c->instances[0].y);
		game->player.moves_to_exit = game->map.paths[y][x];
	}
}

void	is_exit(t_game *game)
{
	if (game->exit_o->count > 0)
	{
		if (game->player.moves_to_exit < -1)
		{
			game->my_error = "Game Lost - You didn't took the shortest way\n";
			clean_exit(game);
		}
		mlx_close_window(game->mlx);
	}
}
