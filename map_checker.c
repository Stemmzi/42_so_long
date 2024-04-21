/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:53:30 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/21 19:50:21 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(t_game *game)
{
	size_t	len;
	int		y;

	len = game->map.length;
	y = 0;
	game->my_error = "Error: Map is not rectangular\n";
	while (y < game->map.height)
	{
		if (len != ft_strlen(game->map.grid[y]))
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
	game->my_error = "Error: Map is not surrounded by Walls\n";
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

int	is_playable(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->my_error = "Error: Map is not playable\n";
	while (y < game->map.height)
	{
		while (x < game->map.length)
		{
			if (game->map.grid[y][x] == 'P')
				has_element('P');
			else if (game->map.grid[y][x] == 'E')
				has_element('E');
			else if (game->map.grid[y][x] == 'C')
				has_element('C');
			x++;
		}
		x = 0;
		y++;
	}
	if (has_element('Y') == 1)
		return (1);
	return (0);
}

void	check_map(t_game *game)
{
	if ((!is_rectangle(game)) || (!is_surrounded_by_walls(game))
		|| (!is_playable(game)))
		clean_exit(game);
	game->my_error = NULL;
}
