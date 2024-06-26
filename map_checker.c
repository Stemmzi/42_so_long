/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:53:30 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/24 01:14:58 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(t_game *game)
{
	size_t	x;
	int		y;

	x = game->map.length;
	y = 0;
	game->my_error = "Error: Map is not rectangular\n";
	while (y < game->map.height)
	{
		if (x != ft_strlen(game->map.grid[y]))
			return (0);
		y++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->my_error = "Error: Map is not surrounded by walls\n";
	while (y < game->map.height)
	{
		if (y == 0 || y == game->map.height)
		{
			while (x < game->map.length)
			{
				if (game->map.grid[y][x] != '1')
					return (0);
				x++;
			}
		}
		else if (game->map.grid[y][0] != '1' ||
			game->map.grid[y][game->map.length - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	has_element(char c)
{
	static int	flag_exit;
	static int	flag_collect;
	static int	flag_player;

	if (c == 'P')
		flag_player++;
	if (c == 'E')
		flag_exit++;
	if (c == 'C')
		flag_collect++;
	if (c == 'Y')
	{
		if (flag_player == 1 && flag_exit == 1 && flag_collect > 0)
			return (1);
	}
	return (0);
}

int	has_items(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	g->my_error = "Error: Map is not playable\n";
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.length)
		{
			if (g->map.grid[y][x] == 'P' || g->map.grid[y][x] == 'E'
				|| g->map.grid[y][x] == 'C')
				has_element(g->map.grid[y][x]);
			else if (g->map.grid[y][x] != '0' && g->map.grid[y][x] != '1')
			{
				g->my_error = "Error: Unknown char in map\n";
				clean_exit(g);
			}
			x++;
		}
		y++;
	}
	if (has_element('Y') == 1)
		return (1);
	return (0);
}

void	check_map(t_game *game)
{
	if ((!is_rectangle(game)) || (!is_surrounded_by_walls(game))
		|| (!has_items(game)))
		clean_exit(game);
	game->my_error = NULL;
	path_finder(game);
}
