/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:56:13 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/23 23:14:15 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y, int value)
{
	if (x > game->map.length - 1 || y > game->map.height - 1)
		return ;
	if (game->map.paths[y][x] == -1)
		return ;
	if (game->map.paths[y][x] != -1)
	{
		if (game->map.paths[y][x] == 0)
			game->map.paths[y][x] = value;
		else if (game->map.paths[y][x] != 0)
		{
			if (game->map.paths[y][x] > value)
				game->map.paths[y][x] = value;
			else
				return ;
		}
	}
	value++;
	flood_fill(game, x + 1, y, value);
	flood_fill(game, x - 1, y, value);
	flood_fill(game, x, y + 1, value);
	flood_fill(game, x, y - 1, value);
}

int	search_collect_path(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		while (x < game->map.length)
		{
			if (game->map.paths[y][x] == 0)
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	check_exit_path(t_game *game)
{
	if (game->map.paths[game->map.exit_pos.y][game->map.exit_pos.x] == 0)
		return (1);
	return (0);
}

void	path_finder(t_game *game)
{
	game->map.exit_pos = find_exit_pos(game);
	game->map.paths = (int **)malloc(game->map.height * sizeof(int *));
	set_path_map_values(game);
	flood_fill(game, game->map.exit_pos.x, game->map.exit_pos.y, 0);
	if (search_collect_path(game) || check_exit_path(game))
	{
		game->my_error = "Exit and/or collectibles are not reachable\n";
		clean_exit(game);
	}
}
