/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:54:45 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/02 21:33:47 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_line(t_game *game, char *line)
{
	static int	y;
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(line);
	while (x < len)
	{
		if (line[x] == '0')
			build_space(game->mlx, x, y);
		if (line[x] == '1')
			build_wall(game->mlx, x, y);
		// if (line[x] == 'C')
		// 	build_collectible(line, x);
		// if (line[x] == 'E')
		// 	build_exit(line, x);
		if (line[x] == 'P')
			build_player(game, game->mlx, x, y);
		x++;
	}
	mlx_set_window_size(game->mlx, 64 * 13, 64 * 5);
	y++;
}

int	create_map(t_game *game, char *argv[])
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		build_line(game, line);
		free(line);
	}
	close(fd);
	return (0);
}
