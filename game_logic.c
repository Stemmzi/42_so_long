/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:22:33 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/18 18:24:06 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == '1')
		return (1);
	return (0);
}

int	find_instance(t_game *game, int x, int y)
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
	int	size;

	count = find_instance(game, x, y);
	size = TILESIZE * SCALE;
	if (game->collect->instances[count].enabled == true)
	{
		game->collect->instances[count].enabled = false;
		game->collect_count--;
	}
	if (game->collect_count == 0 && game->exit_o->count < 1)
	{
		game->exit_c->instances[0].enabled = false;
		mlx_image_to_window(game->mlx, game->exit_o,
			game->exit_c->instances[0].x, game->exit_c->instances[0].y);
	}
}

void	is_exit(t_game *game)
{
	if (game->exit_o->count > 0)
		mlx_close_window(game->mlx);
}
