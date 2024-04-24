/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:01:19 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/24 02:03:23 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_array(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		while (x < game->map.length)
		{
			if (game->map.paths[y][x] >= 0 && game->map.paths[y][x] < 10)
				ft_printf("  ");
			else if (game->map.paths[y][x] >= 10)
				ft_printf(" ");
			else if (game->map.paths[y][x] < 0 && game->map.paths[y][x] > -9)
				ft_printf(" ");
			ft_printf("%d", game->map.paths[y][x]);
			x++;
		}
		ft_printf("\n");
		x = 0;
		y++;
	}
}

t_vec2	get_exit_pos(t_game *game)
{
	t_vec2	pos;
	int		x;
	int		y;

	x = 0;
	y = 0;
	pos.x = x;
	pos.y = y;
	while (y < game->map.height)
	{
		while (x < game->map.length)
		{
			if (game->map.grid[y][x] == 'E')
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (pos);
}

void	set_path_map_values(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < game->map.height)
	{
		game->map.paths[y] = (int *)malloc(game->map.length * sizeof(int));
		while (x < game->map.length)
		{
			if (game->map.grid[y][x] == '1')
				game->map.paths[y][x] = -1;
			else
				game->map.paths[y][x] = 0;
			x++;
		}
		x = 0;
		y++;
	}
}
